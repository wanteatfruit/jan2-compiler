#include "encoder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int string_decode(const char* es, char* s)
{

    const char null_term = '\0';
    int length = strlen(es);
    int s_index = 0;
    int i = 1; // index for es

    if(length>255){
        return 1;
    }

    // case "", avoid """
    if (es[0] == '\"' && es[1] == '\"' && length==2)
    {
        s[0] = '\0';
        return 0;
    }

    // starting and ending "
    if (es[0] != '\"' || es[length - 1] != '\"')
    {
        return 1;
    }

    // parse string
    while (1)
    {
        char cur = es[i];
        if (cur == '\\' && i < length - 2) { // no escaping last "
            char next = es[i + 1];
            if (next == 'a') {
                s[s_index] = 7;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 'b') {
                s[s_index] = 8;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 'e') {
                s[s_index] = 27;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 'f') {
                s[s_index] = 12;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 'n') {
                s[s_index] = 10;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 'r') {
                s[s_index] = 13;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 't') {
                s[s_index] = 9;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == 'v') {
                s[s_index] = 11;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == '\\') {
                s[s_index] = 92;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == '\'') {
                s[s_index] = 39;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == '\"') {
                s[s_index] = 34;
                s_index++;
                i+=2;
                continue;
            }
            else if (next == '0') { //hex or invalid
                char next_x = es[i + 2];
                char next_hex_1 = es[i + 3];
                char next_hex_2 = es[i + 4];
                if (next_x == 'x' && ((next_hex_1 >= '0' && next_hex_1 <= '9') || (next_hex_1 >= 'a' && next_hex_1 <= 'f') || (next_hex_1 >= 'A' && next_hex_1 <= 'F')) && ((next_hex_2 >= '0' && next_hex_2 <= '9') || (next_hex_2 >= 'a' && next_hex_2 <= 'f') || (next_hex_2 >= 'A' && next_hex_2 <= 'F'))) {
                    char hex[3];
                    hex[0] = next_hex_1;
                    hex[1] = next_hex_2;
                    int decimal_value = strtol(hex, NULL, 16);
                    //check if range valid
                    if (decimal_value >=  1 && decimal_value <= 127) { //exluding null
                        s[s_index] = decimal_value;
                        s_index++;
                        i += 5;
                        continue;
                    }
                    else {
                        return 1;
                    }
                }
                else { // invalid next char
                    return 1;
                }
            }else{
                return 1;
            }
        }
        else if (cur == '\"' &&  i==length-1) { // end of string
            s[s_index] = null_term;
            break;
        }
        else if (cur >= 32 && cur <= 126 && cur!=34 && cur!=92) { // normal char
            s[s_index] = es[i];
            s_index++;
            i++;
        }
        else {
            return 1;
        }
    }
    // printf("null-terminated: %s\n", s[strlen(s)]==null_term?"true":"false");
    return 0;
}
int string_encode(const char* s, char* es)
{
    int length = strlen(s);
    int start = 1;
    es[0] = '\"';

    for (int i = 0; i < length; i++)
    {
        char cur = s[i];
        if (cur == 7 || cur == 8 || cur == 27 || cur == 12 || cur == 10 || cur == 13 || cur == 9 || cur == 11 || cur == 92 || cur == 39 || cur == 34)
        {
            es[start] = '\\';
            start++;
            if (cur == 7)
            {
                es[start] = 'a';
            }
            else if (cur == 8)
            {
                es[start] = 'b';
            }
            else if (cur == 27)
            {
                es[start] = 'e';
            }
            else if (cur == 12)
            {
                es[start] = 'f';
            }
            else if (cur == 10)
            {
                es[start] = 'n';
            }
            else if (cur == 13)
            {

                es[start] = 'r';
            }
            else if (cur == 9)
            {

                es[start] = 't';
            }
            else if (cur == 11)
            {

                es[start] = 'v';
            }
            else if (cur == 92)
            {

                es[start] = '\\';
            }
            else if (cur == 39)
            {

                es[start] = '\'';
            }
            else if (cur == 34)
            {

                es[start] = '\"';
            }

        }
        else if(cur<32 || cur>127){//encode into \0xhh format
            es[start] = '\\';
            start++;
            es[start] = '0';
            start++;
            es[start] = 'x';
            start++;
            char hex[3];
            es[start] = hex[0];
            start++;
            es[start] = hex[1];
        }
        else // normal char
        {
            es[start] = s[i];
        }
        start++;
    }
    es[start] = '\"';
    es[start + 1] = '\0';


    return 0;
}

int char_decode(const char* es, char* s ){
    int length = strlen(es);
    // starting and ending ' is guaranteed by scanner
    // content inside guranteed \,0-9,a-z,A-Z by scanner
    if(length==3){ // 'a'
        if(es[1]=='\\'){ // corner case '\'
            return 1;
        }
        s[0] = es[1];
        s[1] = '\0';
        return 0;
    }else if(length==4){ // '\n'
        if(es[1]!='\\'){
            return 1;
        }
        char next = es[2];
        if(next=='a'){
            s[0] = '\\';
            s[1] = 'a';
            s[2] = '\0';
            return 0;
        } else if(next=='b'){
            s[0] = '\\';
            s[1] = 'b';
            s[2] = '\0';
            return 0;
        } else if(next=='e'){
            s[0] = '\\';
            s[1] = 'e';
            s[2] = '\0';
            return 0;
        } else if(next=='f'){
            s[0] = '\\';
            s[1] = 'f';
            s[2] = '\0';
            return 0;
        } else if(next=='n'){
            s[0] = '\\';
            s[1] = 'n';
            s[2] = '\0';
            return 0;
        } else if(next=='r'){
            s[0] = '\\';
            s[1] = 'r';
            s[2] = '\0';
            return 0;
        } else if(next=='t'){
            s[0] = '\\';
            s[1] = 't';
            s[2] = '\0';
            return 0;
        } else if(next=='v'){
            s[0] = '\\';
            s[1] = 'v';
            s[2] = '\0';
            return 0;
        } else if(next=='\\'){
            s[0] = '\\';
            s[1] = '\\';
            s[2] = '\0';
            return 0;
        } else if(next=='\''){
            s[0] = '\\';
            s[1] = '\'';
            s[2] = '\0';
            return 0;
        } else if(next=='\"'){
            s[0] = '\\';
            s[1] = '\"';
            s[2] = '\0';
            return 0;
        } else if(next=='0'){
            s[0] = '\\';
            s[1] = '0';
            s[2] = '\0';
            return 0;
        } else{
            return 1;
        }


    }
    else if(length==7){ // '\0xaa'
        if(es[1]!='\\' || es[2]!='0' || es[3]!='x'){
            return 1;
        }
        char hex[3];
        hex[0] = es[4];
        hex[1] = es[5];
        int decimal_value = strtol(hex, NULL, 16);
        //check if range valid
        if (decimal_value >=  1 && decimal_value <= 127) { //exluding null
            s[0] = decimal_value;
            s[1] = '\0';
            return 0;
        }
        else {
            return 1;
        }
    }else{
        return 1;
    }
    
}
