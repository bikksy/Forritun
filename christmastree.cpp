#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

std::string s="#include<iostream>\n"
"#include<string>\n"
"#include<sstream>\n"
"#include<fstream>\n"
"\n"
"std::string s=\"X\";\n"
"\n"
"              ;\n"
"             ;;;\n"
"              ;\n"
"            using\n"
"          namespace\n"
"        std;/**/string\n"
"      expand/**/(string\n"
"      s, /**/string x){\n"
"     if(s==\"\")return \"\";\n"
"    return(s[0]==(char)88?\n"
"   x:s.substr(0, 1))+expand\n"
"   (s.substr(1), x);}string\n"
"   escape(string s){if(s==\"\"\n"
"   )return\"\";/****/return(s[0\n"
"  ]=='\\n'?\"\\\\n\\\"\\n\\\"\"/**/:s[0]\n"
"  =='\"'?\"\\\\\\\"\":s[0]/**/=='\\\\'\n"
"  ?\"\\\\\\\\\":s.substr(0, 1))/**/\n"
"  +escape(s.substr(1));/**/}\n"
"   int main(){cout<<expand(\n"
"         s,escape(s\n"
"          ))<<endl;\n"
"         return 0;}\n"
"\nGledileg jol!"
"";

              ;
             ;;;
              ;
            using
          namespace
        std;/**/string
      expand/**/(string
      s, /**/string x){
     if(s=="")return "";
    return(s[0]==(char)88?
   x:s.substr(0, 1))+expand
   (s.substr(1), x);}string
   escape(string s){if(s==""
   )return"";/****/return(s[0
  ]=='\n'?"\\n\"\n\""/**/:s[0]
  =='"'?"\\\"":s[0]/**/=='\\'
  ?"\\\\":s.substr(0, 1))/**/
  +escape(s.substr(1));/**/}
   int main(){cout<<expand(
         s,escape(s
          ))<<endl;
         return 0;}