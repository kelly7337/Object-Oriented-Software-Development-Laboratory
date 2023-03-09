// console3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include<sstream>
using namespace std;

//int main()
//{
//    int test[2][3][5] = {
//                            {
//                                {0, 0, 0, 0, 0},
//                                {0, 0, 0, 0, 0},
//                                {0, 0, 0, 0, 0}
//                            },
//                            {
//                                {0, 0, 0, 0, 0},
//                                {0, 0, 0, 0, 0},
//                                {0, 0, 0, 0, 0}
//                            }
//    };
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            for (int k = 0; k < 5; ++k) {
//                test[i][j][k] = i * j * k;
//            }
//        }
//    }
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            for (int k = 0; k < 5; ++k) {
//                cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << endl;
//            }
//        }
//    }
//
//}

//int main(int argc, char* argv[]) {
//	vector<string> s(argc);
//	for (int i = 0; i < argc; ++i) {
//		s.push_back(argv[i]);
//	}
//	for (auto it : s)
//		cout << it;
//	cout << endl;
//	
//}

//int main() {
//    string str = "Ermu Lu";
//    istringstream is(str);
//    string s;
//    while (is >> s)
//        cout << s << endl;
//    
//}

//int main(int argc, char* argv[])
//{
//
//    for (int count{ 0 }; count < argc; ++count)
//    {
//        std::cout << count << ' ' << argv[count] << '\n';
//    }
//
//    return 0;
//}

int main()
{
    int test[2][3][5] = {
                            {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                            },
                            {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                            }
    };
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 5; ++k) {
                test[i][j][k] = i * j * k;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 5; ++k) {
                cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << "address:" << &test[i][j][k] << endl;
            }
        }
    }

}