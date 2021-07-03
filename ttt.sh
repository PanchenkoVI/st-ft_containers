clang++ --std=c++98 -Wall -Wextra -Werror -fsanitize=address  -fno-omit-frame-pointer -g main.cpp
clear
./a.out 
rm a.out
rm -rf a.out.dSYM