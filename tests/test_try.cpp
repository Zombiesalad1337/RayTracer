#include <gtest/gtest.h>
#include "../src/try.h"

TEST(TRY, SUM){
    EXPECT_EQ(4, trying::Sum(2,2));
}
