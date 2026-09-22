import string 
import random
class Encodeur:
    def __init__(self,pwd = None):
        if pwd is None:
            self.password = list(string.ascii_lowercase)
            random.shuffle(self.password)
        else:
            self.password = list(pwd)

    def encode_string(self,input_string):
        return "".join([self.password[ord(c) - ord("a")] if c.islower() else c for c in list(input_string)])

    def encode_file(self,input,output):
        try:
            f = open(input,"r")
            g = open(output,"w")
            input_data = f.read()
            g.write(self.encode_string(input_data))
            f.close()
            g.close()
        except IOError:
            print("Erreur lros de l'ouverture des fichiers")
    
class Decodeur:
    def __init__(self,pwd):
        l = list(zip(pwd,list(string.ascii_lowercase)))
        reverse_pwd = list(string.ascii_lowercase)
        for c in l:
            reverse_pwd[ord(c[0]) - ord("a")] = c[1]
        reverse_pwd = "".join(reverse_pwd)
        self.encode = Encodeur(reverse_pwd)
    
    def decode_string(self,input_string):
        return self.encode.encode_string(input_string)

    def decode_file(self,input,output):
        self.encode.encode_file(input,output)

class CodeBreaker:
    def __init__(self,quadgram):
        
        
