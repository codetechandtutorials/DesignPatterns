/*
rand
----------------------------------------------------------------------
Copyright (c) 2019-2020, Matthew Early matthewjearly@gmail.com
All rights reserved.
Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the
following conditions are met:
* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.
* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.
* Neither the name of the Matthew Early, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission from Matthew Early.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
----------------------------------------------------------------------
*/
#include <random>
#include <chrono>
#include "rand.h"

float ZTORf()
{
  // initialize the random number generator with time-dependent seed
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);
  // initialize a uniform distribution between 0 and 1
  static std::uniform_real_distribution<float> unif(0, 1);
  return unif(mgen);
}

double ZTOR()
{
  // initialize the random number generator with time-dependent seed
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);
  // initialize a uniform distribution between 0 and 1
  static std::uniform_real_distribution<double> unif(0, 1);
  return unif(mgen);
}

int ZOOR()
{
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);
  // initialize a distribution of 0 or 1 randomer
  static std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);
  return dist2(mgen);
}

int NTKR(int n, int k)
{
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);

  // check if user put n <= k to process bounds
  if (n <= k) {
    std::uniform_int_distribution<std::mt19937::result_type> ntkd(n, k);
    return ntkd(mgen);
  }
  else // else n > k, still functions as bounds k to n
  {
    std::uniform_int_distribution<std::mt19937::result_type> ntkd(k, n);
    return ntkd(mgen);
  }
}

float NTKR(float n, float k)
{
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);

  // check if user put n <= k to process bounds
  if (n <= k)
  {
    std::uniform_real_distribution<float> ntkd(n, k);
    return ntkd(mgen);
  }
  else // else n > k, still functions as bounds k to n
  {
    std::uniform_real_distribution<float> ntkd(k, n);
    return ntkd(mgen);
  }
}

double NTKR(double n, double k)
{
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);

  // check if user put n <= k to process bounds
  if (n <= k)
  {
    std::uniform_real_distribution<double> ntkd(n, k);
    return ntkd(mgen);
  }
  else // else n > k, still functions as bounds k to n
  {
    std::uniform_real_distribution<double> ntkd(k, n);
    return ntkd(mgen);
  }
}
