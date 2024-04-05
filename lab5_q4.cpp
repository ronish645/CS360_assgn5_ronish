#include <iostream>
using namespace std;

class Example{
public:
    Example( int y = 10 ): data( y ){
        ++count;
    } // end Example constructor

    int getIncrementedData() {
        return ++data;
    } // end function getIncrementedData

    static int getCount(){
        cout << "Count is " << count << endl;
        return count;
    } // end function getCount

private:
    int data;
    static int count;
}; // end class Example

int Example::count = 0;

int main() {
    Example ex;
    cout << ex.getIncrementedData() << endl;
    Example::getCount();
}
