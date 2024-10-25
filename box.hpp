#ifndef BOX_HPP
#define BOX_HPP


class Box {
    public:
        // Default constructor
        Box() : Lx(1.0), Ly(1.0) {}  // Initializes side to 1.0

        // Parameterized constructor
        Box(double _sidex, double _sidey) : Lx(_sidex), Ly(_sidey) {}  // Initializes side to _side

        // Method to get the side length (optional)
        double get_sidex() const { return Lx; }
        double get_sidey() const { return Ly; }
        void set_sidex(double _sidex) { Lx = _sidex;}
        void set_sidey(double _sidey) { Ly = _sidey;}

    private:
        double Lx;  // Side length of the box
        double Ly;
};

#endif