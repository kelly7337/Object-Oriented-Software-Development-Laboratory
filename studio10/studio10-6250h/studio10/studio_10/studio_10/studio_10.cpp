// studio_10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    multiset<string> mu;
    set<string> se1, se2, out;

    /*std::copy(mu.begin(), mu.end(), std::inserter(foo, it));

   
    std::set_intersection(se1.begin(), se1.end(),
        se2.begin(), se2.end(),
        std::inserter(out));*/
   /* cout << "Number of times 3 appears : "
        << count(mu.begin(), mu.end(), 3);*/

    std::map<std::string, std::ofstream> map;
    map.emplace("foo", std::ofstream("/tmp/foo"));
    map.emplace("bar", std::ofstream("/tmp/bar"));

    map["foo"] << "test";
    map["foo"].flush();

    std::ifstream ifs("/tmp/foo");
    std::string data;
    ifs >> data;

    std::cout << data << '\n';

    return 0;
}



