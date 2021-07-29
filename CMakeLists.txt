cmake_minimum_required(VERSION 3.9)
project(LeetCode)
set(CMAKE_CXX_STANDARD 11)

#链接库
aux_source_directory(leetcode/editor/cn/include LEETCODE)
add_library(leetcode ${LEETCODE})
LINK_LIBRARIES(leetcode)


add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)
add_executable(100-same-tree leetcode/editor/cn/100-same-tree.cpp)
add_executable(100275-ShuZuZhongZhongFuDeShuZiLcof leetcode/editor/cn/100275-ShuZuZhongZhongFuDeShuZiLcof.cpp)
add_executable(100276-ErWeiShuZuZhongDeChaZhaoLcof leetcode/editor/cn/100276-ErWeiShuZuZhongDeChaZhaoLcof.cpp)
add_executable(100280-TiHuanKongGeLcof leetcode/editor/cn/100280-TiHuanKongGeLcof.cpp)
add_executable(100282-CongWeiDaoTouDaYinLianBiaoLcof leetcode/editor/cn/100282-CongWeiDaoTouDaYinLianBiaoLcof.cpp)
add_executable(100283-ZhongJianErChaShuLcof leetcode/editor/cn/100283-ZhongJianErChaShuLcof.cpp)
add_executable(100273-YongLiangGeZhanShiXianDuiLieLcof leetcode/editor/cn/100273-YongLiangGeZhanShiXianDuiLieLcof.cpp)
add_executable(100274-FeiBoNaQiShuLieLcof leetcode/editor/cn/100274-FeiBoNaQiShuLieLcof.cpp)