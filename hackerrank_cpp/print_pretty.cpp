#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        // left and right: Modifies the positioning of the fill characters in an output stream. left and right apply to any type being output, internal applies to integer, floating-point, and monetary output. Has no effect on input.
        // showbase: shows the base of the number hex, dec..
        // nouppercase: do not generate uppercase letters
        // hex: convert to hex
        // setprecisio: how many decimals after the decimal point
        // setw(n): sets the width of output with n chars and fills the empty with '_' by default
        // showpos: show positive: Enables or disables the display of the plus sign '+' in non-negative integer output. Has no effect on input.
        // fixed: When floatfield is set to fixed, floating-point values are written using fixed-point notation: the value is represented with exactly as many digits in the decimal part as specified by the precision field (precision) and with no exponent part.
        // setfill('_'): sets the empty char from setw with given char
        // noshowpos: do not show positive
        // uppercase: show uppercase
        // scientific: shoe numbers in scientific notation
        
		    cout << left << showbase << nouppercase << hex << (long long)A << endl;
                
        cout << setprecision(2) << setw(15) << right << showpos << fixed << setfill('_') << B << endl;
                
        cout << setprecision(9) << noshowpos << uppercase << scientific << C << endl;

	}
	return 0;

}
