// Iordache Tiberiu-Mihai 322CD
// ID moodle: tiberiu.iordache00

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <algorithm>
#include <chrono>
#include "solovay.h"
#include "frobenius.h"

using namespace std;
using namespace std::chrono;

int main() {
    // create the out folder
    mkdir("out", 0777);

    // required for solovay strassen iterations
    int iterations = 100;

    string inpute_name_path = "in/test";

    string output_name_path = "out/test";

    // solovay-strassen test
    // iterate thruogh each test
    for (int i = 0; i < 8; i++) {
        char test_number[2];

        // convert current test number to string
        sprintf(test_number, "%d", i);

        // compute the input file name
        string test_name = inpute_name_path + test_number + ".in";

        // compute the output file name
        string output_file_name = output_name_path + test_number + ".out";

        // open input file
        ifstream infile (test_name);

        // open output file
        ofstream outfile (output_file_name);

        // number of numbers to be tested
        int number;
        // counter for the probable prime numbers
        int counter = 0;
          
        infile >> number;

        // auxiliar array to store the probable prime numbers
        long long prime_numbers[number];

        // used to compute the execution time of the test
        long long sum_duration = 0;

        for (int j = 0; j < number; j++) {
            long long prime_number_to_be_tested;

            infile >> prime_number_to_be_tested;

            // start the timer
            auto start = high_resolution_clock::now(); 

            // check the number
            bool is_prime = solovay_strassen(prime_number_to_be_tested,
                                                iterations);

            // stop the timer
            auto stop = high_resolution_clock::now(); 

            // add the execution time to the sum so we
            //  will compute the average later
            auto duration = duration_cast<nanoseconds>(stop - start);
            sum_duration += duration.count();

            if (is_prime) {
                // if it is probable prime, add it to the array
                prime_numbers[counter] = prime_number_to_be_tested;

                // and increase the size of probable prime numbers
                counter++;
            }
        }

        // print the execution time average
        cout << "solovay test " << i  << " execution time: "
                                      << sum_duration / number 
                                      << " nanoseconds."<< endl;

        // write the results in the output file
        outfile << counter << "\n";

        for (int j = 0; j < counter; j++) {
            outfile << prime_numbers[j] << " ";
        }

        // close the files
        infile.close();
        outfile.close();
    }

    // frobenius test
    
    // new out path
    output_name_path = "out/test1";

    // iterate thruogh each test
    for (int i = 0; i < 8; i++) {
        char test_number[2];
        // convert current test number to string
        sprintf(test_number, "%d", i);

        // compute the input file name
        string test_name = inpute_name_path + test_number + ".in";

        // compute the output file name
        string output_file_name = output_name_path + test_number + ".out";

        // open input file
        ifstream infile (test_name);

        // open output file
        ofstream outfile (output_file_name);

        // number of numbers to be tested
        int number;
        // counter for the probable prime numbers
        int counter = 0;
          
        infile >> number;

        // auxiliar array to store the probable prime numbers
        long long prime_numbers[number];
        
        // used to compute the execution time of the test
        long long sum_duration = 0;

        for (int j = 0; j < number; j++) {
            long long prime_number_to_be_tested;

            infile >> prime_number_to_be_tested;

            // start the timer
            auto start = high_resolution_clock::now(); 

            // check the number
            bool is_prime = frobenius(prime_number_to_be_tested);

            // stop the timer
            auto stop = high_resolution_clock::now(); 

            // add the execution time to the sum so we
            //  will compute the average later
            auto duration = duration_cast<nanoseconds>(stop - start);
            sum_duration += duration.count();

            if (is_prime) {
                // if it is probable prime, add it to the array
                prime_numbers[counter] = prime_number_to_be_tested;

                // and increase the size of probable prime numbers
                counter++;
            }
        }

        // print the execution time average
        cout << "frobenius test " << i  << " execution time: "
                                        << sum_duration / number
                                        << " nanoseconds." << endl;

        // write the results in the output file
        outfile << counter << "\n";

        for (int j = 0; j < counter; j++) {
            outfile << prime_numbers[j] << " ";
        }

        // close the files
        infile.close();
        outfile.close();
    }

    return 0;
}