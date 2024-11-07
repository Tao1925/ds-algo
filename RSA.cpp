#include <iostream>
#include <cmath>
#include <random>

using namespace std;

bool is_prime(uint64_t n) {
    if (n <= 1) return false;      
    if (n <= 3) return true;         
    if (n % 2 == 0 || n % 3 == 0) return false;  

    for (uint64_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

uint64_t gen_prime_by_bit_len(int bit_len) {
    std::random_device rd;  // 用于生成种子
    std::mt19937_64 gen(rd());  // 64位Mersenne Twister引擎

    // 创建一个范围在 uint64_t 最小值和最大值之间的均匀分布
    std::uniform_int_distribution<uint64_t> dis(0, 1 << bit_len);

    while(true){
        uint64_t test_num = dis(gen);
        if (is_prime(test_num))
            return test_num;
    }
}



int main(){

}