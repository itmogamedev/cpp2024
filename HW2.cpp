#include <iostream>

float S_Tr(float b_st, float m_st, float h)
{
    return 0.5 * (b_st + m_st) * h;
}

int main()
{
    std::cout << S_Tr(1, 2, 3);
    return 0;
}
