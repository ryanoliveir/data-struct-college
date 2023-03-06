import os
import sys

DIRECTORY_NUMBER = 25
MAIN_FILE = 'main.cpp'
PATH = os.getcwd()


def createMainFile(path):   
    with open(os.path.join(path, MAIN_FILE), 'w') as main_file:
        pass

def getAbsolutePath(dirName):
    absolute_path: str = os.path.join(PATH, dirName)

    return absolute_path



def createInDirectory(targetDir):
    count: int = 0

    while count < DIRECTORY_NUMBER:
    
        dir_name: str = f'{targetDir}\exercise_{count + 1}'

        os.mkdir(getAbsolutePath(dir_name))
        createMainFile(getAbsolutePath(dir_name))

        count += 1

if __name__ == '__main__':

    if(sys.argv[1] == '--dir'):
        print('[SUCESSS] Creating directorys...')
        createInDirectory(sys.argv[2])
    else:
        print('[ERROR] Invalid flag: %s' % sys.argv[1])






