#include <iostream>
using namespace std;
#include "Capacitor.hpp"
#include <iomanip>

const long double dt = 1e-10; //change in time
const long double final_t = 5e-6; //final time
const long double N = 50000; //num of t_steps
const long double R = 1000; //resistance
const long double C = 100e-12; //capacitance
const long double I_const = 1e-2; //constant current supply
const long double V_const = 10; //constant voltage supply

void constant_c (capacitor &lebron) {
    lebron.current[0] = I_const;
    lebron.voltage[0] = 0;

    for (int t=0;t<N-1;t++) {
        lebron.voltage[t+1] = lebron.voltage[t] + lebron.current[t]*(dt/lebron.c);

        if (t%200 == 0) { 
            cout << "Timestep: " << scientific << lebron.time[t] << endl
            << "Current: " << scientific << lebron.current[t] << endl
            << "Voltage: " << scientific << lebron.voltage[t] << endl;
        }
    }
}

void constant_v (capacitor &lebron) {
    lebron.current[0] = V_const/R;

    for (int t=0;t<N-1;t++) {
        lebron.current[t+1] = lebron.current[t] - lebron.current[t]*(dt/(R*lebron.c));

        if (t%200 == 0) {
            cout << "Timestep: " << scientific << lebron.time[t] << endl 
            << "Current: " << scientific << lebron.current[t] << endl;
        }
    }
}

int main () {
    capacitor lebron;
    lebron.c = C;

    lebron.time = new long double[50000];
    lebron.current = new long double[50000];
    lebron.voltage = new long double[50000];

    for (int i=0;i<N;i++) {
        lebron.time[i] = i*dt;
    }

    cout << "=========================Constant Current Source=========================\n";
    constant_c (lebron);
    cout << "=========================Constant Voltage Source=========================\n";
    constant_v (lebron);

    delete[] lebron.time;
    delete[] lebron.current;
    delete[] lebron.voltage;

    return 0;
}