#include <iostream>
using namespace std;

int main() {
    // Declare integer variables
    int length = 0;
    int width = 0;
    int height = 0;

    // Declare pointers to dynamically allocate memory for each variable
    int* length_ptr = new int;
    int* width_ptr = new int;
    int* height_ptr = new int;

    // Read input values and assign them to both variables and pointers
    cout << "Enter Length: ";
    cin >> *length_ptr;
    length = *length_ptr; 

    cout << "\n Enter Width: ";
    cin >> *width_ptr;
    width = *width_ptr;

    cout << "\n Enter Height: ";
    cin >> *height_ptr;
    height = *height_ptr;

    // Display the variables and their pointers
    cout << "Variables and dynamically allocated memory:" << endl;
    cout << "Length: " << *length_ptr << " stored at address: " << length_ptr << endl;
    cout << "Width: " << *width_ptr << " stored at address: " << width_ptr << endl;
    cout << "Height: " << *height_ptr << " stored at address: " << height_ptr << endl;

    // Free the dynamically allocated memory
    delete length_ptr;
    delete width_ptr;
    delete height_ptr;

    return 0;
}



