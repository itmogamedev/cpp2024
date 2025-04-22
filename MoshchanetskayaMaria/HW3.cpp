#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>

#pragma comment(lib, "user32.lib")

static HWND hButton;
static HWND hTimerLabel;
static HWND hCountdownLabel;
static UINT_PTR timerId = 0;
static int delay = 0;
static int remainingSeconds = 0;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void ShutdownPC();
void UpdateCountdownDisplay(HWND hwnd);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ PSTR szCmdLine, _In_ int iCmdShow)
{
    srand(static_cast<unsigned int>(time(NULL)));

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0,
                     hInstance, LoadIcon(NULL, IDI_APPLICATION), LoadCursor(NULL, IDC_ARROW),
                     (HBRUSH)(COLOR_WINDOW + 1), NULL, L"SabotageTimer", NULL };
    RegisterClassEx(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, L"Таймер Саботажник", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 250, NULL, NULL, hInstance, NULL);

    hButton = CreateWindow(L"BUTTON", L"Завести таймер", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        50, 20, 200, 30, hwnd, (HMENU)1, hInstance, NULL);

    hTimerLabel = CreateWindow(L"STATIC", L"Таймер не активен", WS_VISIBLE | WS_CHILD,
        50, 70, 200, 30, hwnd, NULL, hInstance, NULL);

    hCountdownLabel = CreateWindow(L"STATIC", L"Осталось: --:--", WS_VISIBLE | WS_CHILD | SS_CENTER,
        50, 120, 200, 40, hwnd, NULL, hInstance, NULL);

    HFONT hFont = CreateFont(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
        VARIABLE_PITCH, L"Arial");
    SendMessage(hCountdownLabel, WM_SETFONT, (WPARAM)hFont, TRUE);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return static_cast<int>(msg.wParam);
}

void UpdateCountdownDisplay(HWND hwnd) {
    if (remainingSeconds <= 0) {
        SetWindowText(hCountdownLabel, L"00:00");
        return;
    }

    int minutes = remainingSeconds / 60;
    int seconds = remainingSeconds % 60;

    std::wstringstream ss;
    ss << L"Осталось: " << std::setw(2) << std::setfill(L'0') << minutes << L":"
        << std::setw(2) << std::setfill(L'0') << seconds;

    SetWindowText(hCountdownLabel, ss.str().c_str());
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_COMMAND:
        if (LOWORD(wParam) == 1 && timerId == 0) {
            delay = 10 + rand() % 50;
            remainingSeconds = delay;
            SetWindowText(hTimerLabel, L"Таймер активирован!");
            UpdateCountdownDisplay(hwnd);
            timerId = SetTimer(hwnd, 1, 1000, NULL); 
        }
        break;

    case WM_TIMER:
        remainingSeconds--;
        UpdateCountdownDisplay(hwnd);

        if (remainingSeconds <= 0) {
            KillTimer(hwnd, timerId);
            timerId = 0;
            ShutdownPC();
            SetWindowText(hTimerLabel, L"Компьютер выключается!");
        }
        break;

    case WM_DESTROY:
        if (timerId != 0) KillTimer(hwnd, timerId);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void ShutdownPC() {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    CreateProcess(NULL, (LPWSTR)L"shutdown /s /t 1", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}