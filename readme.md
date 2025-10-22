How I solved the basic "baby keygen 4" challenge.

# I begun by just using IDA, instead of using strings as how I do with level 1-2 crackmes.

So, we encounter the main function:
For one we can tell this.
1. We call scuffed names such as functim functions, functionss. Hence the author's lightweight obfuscation.
2. strcpy is called likely copying a string somewhere.
3. Now we skip to cmp [rbp+var9] == 3, I would assume this is the checker because the last time three characters are compared in the check.
<img width="399" height="623" alt="ads" src="https://github.com/user-attachments/assets/b5a4805d-4fdb-4fd6-a523-aa189b1b7c83" />



# After the above we go down to the JNZ.
1. Jump if not zero is JNZ in assembly.
2. This here shown is what happens upon these checks.

# Horrible art incoming.
I am a amazing artist hands down, sike!
<img width="433" height="382" alt="IDA - 7-BabyKegen-4-Obfuscated exe C__Users_Rands_OneDrive_Desktop_7-BabyKegen-4-Obfuscated exe 10_22_2025 9_53_35 AM" src="https://github.com/user-attachments/assets/2559aacb-7906-4ccb-ad21-873a59214ec8" />


# Onto the checker.
1. Now we can see strcpy being used `mov [rbp+varz]` This [] is a pointer being dereferenced.
2. Now for the second argument of strcpy we can see rax moved into rcx, our destination.
3. Now after strcpy has copied contents over we can move down to: `mov [rbp+length], eax`
4. We compare 11 to our pointer and jump if not zero to fail out the hacker for inserting a key over 11 chars.
<img width="614" height="652" alt="IDA - 7-BabyKegen-4-Obfuscated exe C__Users_Rands_OneDrive_Desktop_7-BabyKegen-4-Obfuscated exe 10_22_2025 9_55_58 AM" src="https://github.com/user-attachments/assets/3ac05ff5-cd35-44ba-a484-5174a55ced45" />


# Our key checker.
1. We can see A, X, X together here, each of these if you miss the input will fail the key validation.
2. Our add operations also hint out the fact the key checking would be passed with input such as "ACAXTRAXIN1"
3. Let's walk the walk now.
```c
             ________________________________________________
           |                                                  |
           |    _________________________________________     |
           |   |                                         |    |
           |   |  C:> Keygen-me by 2ourc3                |    |
           |   |  C:> Please find the PASS               |    |
           |   |  C:> and write a Keygen                 |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |_________________________________________|    |
           |                                                  |
            _________________________________________________/
                   ___________________________________/
                ___________________________________________
             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_
          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_
       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_
    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_
 _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_
:-------------------------------------------------------------------------:
`---._.-------------------------------------------------------------._.---'




Please enter a valid KEY: ACAXTRAXIN1
The key entered is valid
```

I will put a fully compilable version based off what I see in here alone.
