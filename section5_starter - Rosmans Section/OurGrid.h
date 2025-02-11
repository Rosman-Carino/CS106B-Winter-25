#pragma once

class OurGrid {
public:
    /* Creates a new grid of size numRows x numCols. If either numRows or
     * numCols is negative, this calls error(). Initially, all values in the
     * Grid are set to 0.
     */
    OurGrid(int numRows, int numCols);
    ~OurGrid();

    /* Returns whether the given point is in bounds. */
    bool inBounds(int row, int col) const;

    /* Returns the value at the given (row, col) index. If the index is out of
     * bounds, calls error().
     */
    int get(int row, int col) const;

    /* Sets the value at (row, col) to the specified value. If the index is out
     * of bounds, calls error().
     */
    void set(int row, int col, int value);

    /* Returns the number of rows or columns in the grid, respectively. */
    int numRows() const;
    int numCols() const;

private:
    /* Pointer to an array of pointers. Each of those pointers then points to
     * the contents of a row.
     */
    int** elems;
};
