class point{
    private:
        double x, y, z;
    public:
        point();
        point(double, double, double);
        void negate();
        double norm() const;
        point operator+(const point&) const;
        double getX() const;
        double getY() const;
        double getZ() const;
};