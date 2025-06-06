class Time {
  float m_time = 0.0f;
  float m_delta_time = 0.0f;

public:
  static Time& get() {
    static Time instance;
    return instance;
  }

  void update(float delta_time) {
    m_delta_time = delta_time;
    m_time += delta_time;
  }

  [[nodiscard]] float delta_time() const {
    return m_delta_time;
  }
  [[nodiscard]] float time() const {
    return m_time;
  }
};