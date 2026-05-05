#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings, string member functions
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          This is a limited disassembler: we can safely assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti, sltiu
//          c) has ONLY registers $t0 thru $t7, or $s0 thru $s7 in the instruction
//
string disassemble( string hex ) {

    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the 
    //      different parts of the hex instruction!
    
    // YOUR CODE GOES HERE!!
    unsigned int val = stoul(hex, nullptr, 16);
    int opcode = (val >> 26) & 0x3F;
    int rs = (val >> 21) & 0x1F;
    int rt = (val >> 16) & 0x1F;
    short immediate = (short)(val & 0xFFFF);

    string op_str = "";
    if(opcode == 8) op_str = "addi";
    else if(opcode == 9) op_str = "addiu";
    else if(opcode == 12) op_str = "andi";
    else if(opcode == 13) op_str = "ori";
    else if(opcode == 10) op_str = "slti";
    else if(opcode == 11) op_str = "sltiu";

    string rs_str = "";
    string rt_str = "";

    if (rs >= 8 && rs <= 15) rs_str = "$t" + to_string(rs - 8);
    else if (rs >= 16 && rs <= 23) rs_str = "$s" + to_string(rs - 16);

    if (rt >= 8 && rt <= 15) rt_str = "$t" + to_string(rt - 8);
    else if (rt >= 16 && rt <= 23) rt_str = "$s" + to_string(rt - 16);

    return op_str + " " + rt_str + ", " + rs_str + ", " + to_string(immediate);
}

int main() {
// Do NOT change ANY code in main() function!!
//      or you will fail this task (get a zero)

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
