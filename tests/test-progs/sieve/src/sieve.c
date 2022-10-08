/*
 * Copyright (c) 2006 The Regents of The University of Michigan
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* C program for counting primes number smaller than or euqal to n using
 * Sieve of Eratosthenes
 * gem5 101 homework1
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void SieveOfEratosthenes (int n)
{
    // Create a boolean array prime for number 2, ..., n
    // initialize all entries as true
    // if a number in prime list is not prime
    // it will be set as false
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    // scan all numbers from 2 to sqrt(n)
    for (int p = 2; p * p <= n; ++p) {
        // if prime[p] is true, than its a prime
        // need to scan all of its multiples
        if (prime[p]) {
            // set all multiples of p as false
            // note: multiples of p that smaller than p^2
            // has already been marked
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // count the number of primes
    int cnt = 0;
    for (int p = 2; p <= n; ++p) {
        if (prime[p]) cnt += 1;
    }
    printf("Prime Number: %d\n", cnt);
} // SieveOfEratosthenes

int main(int argc, char* argv[])
{
    int n = 100;
    SieveOfEratosthenes(n);

    return 0;
}

