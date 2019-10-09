// Utils file


//////////////////////////////////////////////////////////////
// Point 2D
//////////////////////////////////////////////////////////////
class Point2D
{
public:
    constexpr Point2D() = default;
    constexpr Point2D(float x, float y) : m_x(x), m_y(y) {};
    constexpr Point2D(const Point2D& other) : m_x(other.m_x), m_y(other.m_y) {};
    constexpr Point2D(Point2D&& other) = default;

    constexpr void operator+=(const Point2D& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
    };

    constexpr void operator-=(const Point2D& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
    };

    constexpr void operator*=(float factor)
    {
        m_x *= factor;
        m_y *= factor;
    };

    constexpr Point2D operator+(const Point2D& other) const
    {
        Point2D res{ *this };
        res += other;
        return res;
    };

    constexpr Point2D operator-() const
    {
        Point2D res{ *this };
        res *= -1.0f;
        return res;
    };

    constexpr Point2D operator-(const Point2D& other) const
    {
        Point2D res{ *this };
        res -= other;
        return res;
    };

    constexpr Point2D operator*(float factor) const
    {
        Point2D res{ *this };
        res *= factor;
        return res;
    };

    constexpr float Dot(const Point2D& other) const
    {
        return m_x * other.m_x + m_y * other.m_y;
    };

    constexpr float Cross(const Point2D& other) const
    {
        return m_x * other.m_y - m_y * other.m_x;
    };

private:
    float m_x = 0.0f;
    float m_y = 0.0f;
};