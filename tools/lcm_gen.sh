#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -e "${GREEN} Starting LCM type generation...${NC}"

# Clean
if [ -d "../lcm_types" ];
then
  rm -r ../lcm_types
fi

mkdir -p ../lcm_types
cd ../lcm_types

# Make
lcm-gen -jxp ../*/*.lcm # 生成java,c++,python
cp /usr/local/share/java/lcm.jar . # 获取lcm.jar
javac -cp lcm.jar */*.java    # 生成class
jar cf customize_types.jar */*.class # 消息打包，用于lcm-spy解析

# 整理
mkdir -p java
mv *.jar java

FILES=$(ls */*.class)
echo ${FILES} > file_list.txt

echo -e "${GREEN} Done with LCM type generation${NC}"