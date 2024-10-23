#ifndef BOX_HPP
#define BOX_HPP


class Box {
    public:
        // Default constructor
        Box() : side(1.0) {}  // Initializes side to 1.0

        // Parameterized constructor
        Box(double _side) : side(_side) {}  // Initializes side to _side

        // Method to get the side length (optional)
        double get_side() const { return side; }
        void set_side(double _side) { side = _side;}

    private:
        double side;  // Side length of the box
};

#endif