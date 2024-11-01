# YoinkleScript
> A high-level, dynamic, object-oriented, interpreted programming language

## Goal
The goal behind YoinkleScript for me is to learn more about how programming languages are built and how the interpreted ones, interpret code and execute the code.
By building a programming language myself I can get a better understanding of every aspect of how a programming language is constructed. And it's also just a fun project to work on.

<br/>

## Progress
#### Essential
- [x] File reader
- [x] Execution arguments
- [x] Tokenizer
- [x] Parser
- [x] Runtime
- [x] Syntax Highlighting
#### Can be done later
- [x] Builtins/standard library
- [x] Installer
- [x] Documentation



## Syntax
> [!IMPORTANT]
> As I'm writing this, YoinkleScript is still in development and may not even be finished. This means that the documentation below might be incorrect or outdated
### Variables
YoinkleScript has a easy to learn syntax that is similar to other programming languages like JavaScript and Python. YoinkleScript offers dynamic typing which means that int, float and string typing is not needed.
```javascript
new_int = 155;
new_flt = 1.5;
new_bool = True;
new_doubleq_str = "hello world";
new_singleq_str = 'hello world';
```

<br/>

### Builtins
YoinkleScript has been designed to be community driven, this is why YoinkleScript doesn't offer as many built in functions like Javascript or Python. I want to encourage people to make their own functions and learn from building applications in that way. YoinkleScript is not absolutely bare bone ofcourse. It offers some minimum level of built in functions like print and read.
```javascript
answer = read("Did bob built something?: ");
print("%V", answer);
```

<br/>

### Keywords
Keywords in YoinkleScript are very similar to keywords in Python, Ruby and JavaScript. YoinkleScript uses many keywords liek if, else and return that are quite similar to what other programming languages offer. The function keyword (``def`` in python) is task in YoinkleScript.

Functions
```javascript
task my_new_task(arg_1) {
    return "hello there"
};
```

If-else
```javascript
if (True) {
    print("yep");
} else {
    print("nope");
};
```

<br/>

## Extra's
YoinkleScript also knows some flags. The flags can be found by using the ``-h/--help`` flag. This will display all the available flags and how the flags should be set and what they expect.
```
Usage: C:\Users\Name\Documents\YoinkleScript\main.exe [flags] [file_path]
Arguments and flags:
  -h, --help      Display this help message
  -v, --version   Display the version
  -d, --debug     Add behind your script to run in debug
  -t              Add behind your script to view the tokens
  -a              Add behind your script to view abstract syntax tree
  -f              Add behind your script to view the file path
  -c              Add behind your script to view the code
  file            The path to the file you want to run
```

<br/>

> [!CAUTION]
> As the creator of YoinkleScript, I hereby declare that the software is provided "as is" without any warranty of any kind, either express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, or non-infringement. I am not liable for any bugs, errors, or issues that may arise from the use of YoinkleScript. By using this programming language, you acknowledge and accept that any consequences, including potential data loss, system crashes, or other malfunctions, are solely your responsibility. Use YoinkleScript at your own risk.
