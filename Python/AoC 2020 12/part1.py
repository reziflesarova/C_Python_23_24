class Lod:
    def __init__(self, stupne, sever, vychod):
        self.stupne = stupne
        self.sever = sever
        self.vychod = vychod

    def naviguj(self, soubor):
        with open(soubor, 'r') as myfile:
            for radek in myfile:
                ukol = radek[0]
                hodnota = int(radek[1:])
                if ukol in ['L', 'R']:
                    self.rotace(ukol, hodnota)
                elif ukol in ['N', 'S', 'E', 'W', 'F']:
                    self.pohyb(ukol, hodnota)

    def pohyb(self, smer, hodnota):
        if smer == 'N':
            self.sever += hodnota
        elif smer == 'S':
            self.sever -= hodnota
        elif smer == 'E':
            self.vychod += hodnota
        elif smer == 'W':
            self.vychod -= hodnota
        elif smer in ['L', 'R']:
            self.rotace(smer, hodnota)
        elif smer == 'F':
            if self.stupne == 0:
                self.sever += hodnota
            elif self.stupne == 90:
                self.vychod += hodnota
            elif self.stupne == 180:
                self.sever -= hodnota
            elif self.stupne == 270:
                self.vychod -= hodnota

    def rotace(self, smer, hodnota):
        if smer == 'L':
            self.stupne -= hodnota
        elif smer == 'R':
            self.stupne += hodnota
        if self.stupne < 0:
            self.stupne += 360
        elif self.stupne >= 360:
            self.stupne -= 360

    def tisk_souradnic(self):
        print(abs(self.sever) + abs(self.vychod))


novaLod = Lod(90, 0, 0)
novaLod.naviguj("test.txt")
novaLod.tisk_souradnic()