class NavigacniBod:
    def __init__(self):
        self.sever = 2
        self.vychod = 10

    def rotace(self, smer, hodnota):
        if smer == 'L':
            pomX = self.vychod
            pomY = self.sever

            if hodnota == 90:
                self.vychod = -pomY
                self.sever = +pomX
            elif hodnota == 180:
                self.vychod = -pomX
                self.sever = -pomY
            elif hodnota == 270:
                self.vychod = pomY
                self.sever = -pomX

        elif smer == 'R':
            stupen = 360 - hodnota

            pomX = self.vychod
            pomY = self.sever

            if stupen == 90:
                self.vychod = -pomY
                self.sever = +pomX
            elif stupen == 180:
                self.vychod = -pomX
                self.sever = -pomY
            elif stupen == 270:
                self.vychod = pomY
                self.sever = -pomX

    def posun(self, smer, hodnota):
        if smer == 'N':
            self.sever += hodnota
        elif smer == 'S':
            self.sever -= hodnota
        elif smer == 'E':
            self.vychod += hodnota
        elif smer == 'W':
            self.vychod -= hodnota


class Lod:
    def __init__(self):
        self.sever = 0
        self.vychod = 0
        self.nav_bod = NavigacniBod()

    def pohyb(self, hodnota):
        self.sever += (self.nav_bod.sever * hodnota)
        self.vychod += (self.nav_bod.vychod * hodnota)

    def naviguj(self, soubor):
        with open(soubor, 'r') as myfile:
            for radek in myfile:
                ukol = radek[0]
                hodnota = int(radek[1:])
                if ukol in ['L', 'R']:
                    self.nav_bod.rotace(ukol, hodnota)
                elif ukol in ['N', 'S', 'E', 'W']:
                    self.nav_bod.posun(ukol, hodnota)
                elif ukol == 'F':
                    self.pohyb(hodnota)

    def tisk_souradnic(self):
        print(abs(self.sever) + abs(self.vychod))


novaLod = Lod()
novaLod.naviguj("souradnice.txt")
novaLod.tisk_souradnic()