#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 选择置换1(我也不知道为什么要叫这个名字)
uint64_t PC1(uint64_t ull_data){
    uint64_t ull_ret = 0ull;
    uint32_t ret_l = 0, ret_r = 0;
    int pc1_l[28] = {57, 49, 41, 33, 25, 17, 9, 
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36};
    int pc1_r[28] = {63, 55, 47, 39, 31, 23, 15, 
                     7, 62, 54, 46, 38, 30, 22, 
                     14, 6, 61, 53, 45, 37, 29, 
                     21, 13, 5, 28, 20, 12, 4};
    for (int i = 0; i < 28; i++){
        ret_l += ((ull_data >> (pc1_l[i] - 1)) & 1) << i;
        ret_r += ((ull_data >> (pc1_r[i] - 1)) & 1) << i;
    }
    ull_ret = ret_l << 32 + ret_r;
    return ull_ret;
}

uint64_t PC2(uint64_t ull_data){
    uint64_t ull_ret = 0ull;

    int pc2[48] = {14, 17, 11, 24, 1, 5, 
                   3, 28, 15, 6, 21, 10,
                   23, 19, 12, 4, 26, 8,
                   16, 7, 27, 20, 13, 2,
                   41, 52, 31, 37, 47, 55,
                   30, 40, 51, 45, 33, 48,
                   44, 49, 39, 56, 34, 53,
                   46, 42, 50, 36, 29, 32};

    for (int i = 0; i < 48; i++){
        ull_ret = ((ull_data >> (pc2[i] - 1)) & 1) << i;
    }
    return ull_ret;
}

uint32_t P(uint32_t data){
    uint32_t ret = 0ull;

    int p[32] = {16, 7, 20, 21,
                29, 12, 28, 17,
                1, 15, 23, 26,
                5, 18, 31, 10,
                2, 8, 24, 14,
                32, 27, 3, 9,
                19, 13, 30, 6,
                22, 11, 4, 25};

    for (int i = 0; i < 32; i++){
        ret = ((data >> (p[i] - 1)) & 1) << i;
    }
    return ret;
}
// e-expand
uint64_t int32_to_48(uint32_t data){
    uint64_t ull_ret = 0;
    int e[48] = {32, 1, 2, 3, 4, 5,
                 4, 5, 6, 7, 8, 9,
                8, 9, 10, 11, 12, 13,
                 12, 13, 14, 15, 16, 17,
                 16, 17, 18, 19, 20, 21,
                 20, 21, 22, 23, 24, 25,
                 24, 25, 26, 27, 28, 29,
                 28, 29, 30, 31, 32, 1};
    for (int i = 0; i < 48; i++){
        ull_ret += (data >> (e[i] - 1) & 1) << i;
    }
    return ull_ret;
}

uint32_t S(uint64_t ull_step1){

    uint32_t ret  = 0;

    int S_box[8][64] = {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
                        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
                        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
                        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}, 
                        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
                        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
                        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
                        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}, 
                        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
                        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
                        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
                        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
                        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
                        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
                        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
                        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
                        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
                        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
                        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
                        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
                        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
                        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
                        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
                        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
                        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
                        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
                        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
                        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
                        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
                        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
                        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
                        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}};
    for (int i = 0; i < 8; i++){
        uint8_t data_6bit = static_cast<uint8_t>((ull_step1 >> (8 * i)) & 0x3F);
        int index = (data_6bit >> 5) * 32 + (data_6bit & 1) * 16 + (data_6bit >> 1) & 0xF;
        uint8_t s_data = S_box[i][index];
        ret += static_cast<uint32_t>(s_data) << (4 * i);
    }
    return ret;
}

uint64_t go_round(uint32_t l, uint32_t r, uint64_t subkey){

    uint64_t ull_step1 = int32_to_48(r) ^ subkey;
    uint32_t step2 = S(ull_step1);
    uint32_t step3 = P(step2); 
    uint64_t ret =  static_cast<uint64_t>(r) << 32 + l ^ step2;
    return ret;
}

// 64bit key -> 16* 48bit subkey
vector<uint64_t> gen_keys(uint64_t ull_key){
    uint64_t ull_ret = PC1(ull_key);
    uint32_t ret_l = static_cast<uint32_t>(ull_ret >> 32); 
    uint32_t ret_r = static_cast<uint32_t>(ull_ret & 0xFFFFFFFF);

    vector<uint64_t> ull_subkeys;
    int off[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    for (int i = 0; i < 16; i++){
        while(off[i]--){
            ret_l = ret_l >> 28 + (ret_l & (1 << 28 - 1) * 2);
            ret_r = ret_r >> 28 + (ret_r & (1 << 28 - 1) * 2);
        }
        ull_subkeys.push_back(PC2(static_cast<uint64_t>(ret_l) << 28 + ret_r));
    }

    return ull_subkeys;
}


uint64_t DES(uint64_t ull_plain, uint64_t ull_key, bool crypt_type){
    vector<uint64_t> ull_subkeys = gen_keys(ull_key);
    
    if (crypt_type) reverse(ull_subkeys.begin(), ull_subkeys.end());

    uint32_t plain_l = static_cast<uint32_t>(ull_plain >> 32); 
    uint32_t plain_r = static_cast<uint32_t>(ull_plain & 0xFFFFFFFF);

    for (int i = 0; i < 16; i++){
        uint64_t ull_ret = go_round(plain_l, plain_r, ull_subkeys[i]);
        plain_l = static_cast<uint32_t>(ull_ret >> 32); 
        plain_r = static_cast<uint32_t>(ull_ret & 0xFFFFFFFF);
    }

    uint64_t ret = static_cast<uint64_t>(plain_l) << 32 + plain_r;

    return ret;
}

int main()
{
    cout << hex << DES(0x11aabbccddeeff01, 0xcafababedeadbeaf, 'encrypt') << endl; // 0x2973a7e54ec730a3
    cout << hex << DES(0x2973a7e54ec730a3, 0xcafababedeadbeaf, 'decrypt') << endl; // 0x11aabbccddeeff01
    return 0;
}
