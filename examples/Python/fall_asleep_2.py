class Sheep:
    x = 0
    name = "Just another sheep"

    def __init__(self, name=name):
        """I construct Sheep instances"""
        self.name = name
        print('{0} speaking: I am constructed :-)'.format(self.name))

    def flock(self):
        self.x = self.x + 1
        print('{0} flock count: {1}'.format(self.name, self.x))

    def __del__(self):
        print('{0} speaking: I am destructed :-('.format(self.name))

    def __str__(self):
        info = '(x = {0}, name = {1})'.format(str(self.x), str(self.name))
        return info 

class Lamb(Sheep):
    siblings = 0

    def __str__(self):
        info = '(x = {0}, name = {1}, siblings = {2})'.format(str(self.x), str(self.name), str(self.siblings))
        return info 

    def set_siblings(self, s):
        self.siblings = s
        print('{0} speaking: I have {1} siblings'.format(self.name, self.siblings))
        for i in range(s):
            self.flock()
        
montauciel = Sheep("Montauciel")
montauciel.flock()
dolly = Lamb("Dolly")
dolly.flock()
dolly.set_siblings(3)
print(dolly)
print(montauciel)
