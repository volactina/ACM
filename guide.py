# Choose OJ
OJs = ['leetcode', 'nowcoder']
print("welcome to use the guide service for ACM project!")
input_finish = False
while not input_finish:
    print("which OJ are you using? Please choose from OJs list below")
    for OJ in OJs:
        print(OJ)
    targetOJ = input("The OJ you are using now is (or enter exit to leave):")
    if targetOJ == "exit":
        print("OK Bye! See you next time!")
        exit(0)
    if targetOJ in OJs:
        input_finish = True
    else:
        print("Sorry the OJ you choose is not supported, please choose again")

#choose Language
Languages = ['c', 'c++', 'java', 'python']
print("OK, so now you using " + targetOJ)
print("Then which language are you using? The supporting Language is listed below")
input_finish = False
while not input_finish:  
    for Language in Languages:
        print(Language)
    targetLanguage = input("The language you are using is (or enter exit to leave):")
    if targetLanguage == "exit":
        print("OK Bye! See you next time!")
        exit(0)
    if targetLanguage in Languages:
        input_finish = True
    else:
        print("Sorry the Language you choose is not supported, please choose again")
#enter problem id
input_finish = False
print("Ok so you are now writing " + targetLanguage + " on " + targetOJ)
problemID = input("Please tell us the problem id(or enter exit to leave):")
if problemID == "exit":
    print("OK Bye! See you next time!")
    exit(0)
#creating new folder using template
folder_dir = "src\\" + targetOJ + "\\" + problemID
template_dir = "template\\" + targetOJ + "\\" + targetLanguage
print("The new foler will be " + folder_dir)
print("The template use is " + template_dir)
input_finish = False
while not input_finish:
    confirm = input("Please confirm again if you want to continue(y/n):")
    if confirm == "y":
        input_finish = True
    elif confirm == "n":
        input_finish = False
        print("OK Bye! See you next time!")
        exit(0)
print("Creating folder for you....")
import os
if not os.path.exists(template_dir):
    print("Sorry template not exist")
    exit(0)
if os.path.exists(folder_dir):
    print(folder_dir + " already exist")
    exit(0)
os.mkdir(folder_dir)
import shutil
for file in os.listdir(template_dir):
    shutil.copy(template_dir + "\\" + file, folder_dir)
print("Done!")
os.system("start explorer %s" % os.path.abspath(folder_dir))
# should figure out a way to open or close cmd and cd to the path
# os.system("cd %s" % os.path.abspath(folder_dir))