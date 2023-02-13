#需求的最低cmake程序版本
cmake_minimum_required(VERSION 3.12)

#本工程的名字
project(Graphic)

#本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

#把需要拷贝的资源路径都放到ASSETS里
file(GLOB ASSETS "./assets" "thirdParty/assimp-vc143-mtd.dll")

#把ASSETS指代的目录集合的内容，都拷贝到可执行文件目录下
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})


#将funcs文件夹纳入到编译系统
add_subdirectory(funcs)

#本工程主程序文件及输出程序名称
#add_executable(softRenderer "main.cpp" "ADD.cpp" "ADD.h")

#上面用以下替代
#搜索所有的cpp，加入SRCS变量中
aux_source_directory(. SRCS)
#本工程所有cpp文件编译链接，生成exe
#add_executable(softRenderer ${SRCS})

#加入main2后使用"main.cpp"而不是${SRCS},不然会包括main2
add_executable(softRenderer "main.cpp")

#运行main2
add_executable(main2 "main2.cpp")

#将funcs.lib链接入softRender
target_link_libraries(softRenderer funcs)