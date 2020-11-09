#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, ningunaViva){
    toroide t = { {false, false, false, false, false, false},
                  {false, false, false, false, false, false},
                  {false, false, false, false, false, false},
                  {false, false, false, false, false, false} };

    int res = densidadPoblacion(t);
    EXPECT_EQ(res, 0);
}