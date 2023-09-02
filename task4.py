class Villain:
    def __init__(self, name, health=100, energy=500):
        self.name = name
        self.health = health
        self.energy = energy
        self.shield = None

    def attack(self, other):
        pass

    def defend(self):
        pass

    def take_damage(self, damage,energyloss):
        if self.shield:
            damage *= (1 - self.shield)
        self.health -= damage
        self.energy-=energyloss

    def is_defeated(self):
        return self.health <= 0


class Gru(Villain):
    def __init__(self, name):
        super().__init__(name)

    def attack(self, other):
        weapon = self.choose_weapon()
        weapon.use(other)

    def defend(self):
        shield = self.choose_shield()
        self.shield = shield.save_percentage

    def choose_weapon(self):
        available_weapons = [FreezeGun(), ElectricProd(), MegaMagnet(), KalmanMissile()]
        print(f"{self.name}, choose your weapon:")
        for i, weapon in enumerate(available_weapons):
            print(f"{i+1}. {weapon.__class__.__name__}")
        choice = int(input("Enter the number of the weapon you want to use: ")) - 1
        match choice:
            case 0:
                return available_weapons[choice]
            case 1:
                if available_weapons[choice].resources==0:
                   print("Insufficient weapon ... please choose another weapon")
                   Villain.choose_weapon(self)
                else:
                   return available_weapons[choice]
            case 2:
                if available_weapons[choice].resources==0:
                   print("Insufficient weapon ... please choose another weapon")
                   Villain.choose_weapon(self)
                else:
                   return available_weapons[choice]
            case 3:
                if available_weapons[choice].resources==0:
                   print("Insufficient weapon ... please choose another weapon")
                   Villain.choose_weapon(self)
                else:
                   return available_weapons[choice]
            case _:
                print("Please enter a number from 1 to 4")
                Villain.choose_weapon(self)

    def choose_shield(self):
        available_shields = [EnergyProjectedBarrierGun(), SelectivePermeability()]
        print(f"{self.name}, choose your shield:")
        for i, shield in enumerate(available_shields):
            print(f"{i+1}. {shield.__class__.__name__}")
        choice = int(input("Enter the number of the shield you want to use: ")) - 1
        match choice:
            case 0:
                return available_shields[choice]
            case 1:
                if available_shields[choice].resources==0:
                   print("Insufficient shield ... please choose another shield")
                   Villain.choose_shield(self)
                else:
                   return available_shields[choice]
            case _:
                print("Please enter a number from either 1 or 2")
                Villain.choose_shield(self)


class Vector(Villain):
    def __init__(self, name):
        super().__init__(name)

    def attack(self, other):
        weapon = self.choose_weapon()
        weapon.use(other)

    def defend(self):
        shield = self.choose_shield()
        self.shield = shield.save_percentage

    def choose_weapon(self):
        available_weapons = [LaserBlasters(), PlasmaGrenades(), SonicResonanceCannon()]
        print(f"{self.name}, choose your weapon:")
        for i, weapon in enumerate(available_weapons):
            print(f"{i+1}. {weapon.__class__.__name__}")
        choice = int(input("Enter the number of the weapon you want to use: ")) - 1
        match choice:
            case 0:
                return available_weapons[choice]
            case 1:
                if available_weapons[choice].resources==0:
                   print("Insufficient weapon ... please choose another weapon")
                   Villain.choose_weapon(self)
                else:
                   return available_weapons[choice]
            case 2:
                if available_weapons[choice].resources==0:
                   print("Insufficient weapon ... please choose another weapon")
                   Villain.choose_weapon(self)
                else:
                   return available_weapons[choice]
            case _:
                print("Please enter a number from 1 to 3")
                Villain.choose_weapon(self)

    def choose_shield(self):
        available_shields = [EnergyNetTrap(), QuantumDeflector()]
        print(f"{self.name}, choose your shield:")
        for i, shield in enumerate(available_shields):
            print(f"{i+1}. {shield.__class__.__name__}")
        choice = int(input("Enter the number of the shield you want to use: ")) - 1
        match choice:
            case 0:
               return available_shields[choice]
            case 1:
                if available_shields[choice].resources==0:
                   print("Insufficient shield ... please choose another shield")
                   Villain.choose_shield(self)
                else:
                   return available_shields[choice]
            case _:
               print("Please enter either 1 or 2")
               Villain.choose_shield(self)


class Weapon:
    def __init__(self, energy, damage, resources):
        self.energy = energy
        self.damage = damage
        self.resources = resources

    def use(self, target):
        pass


class FreezeGun(Weapon):
    def __init__(self):
        super().__init__(50, 11, float('inf'))

    def use(self, target):
            target.take_damage(self.damage,self.energy)


class ElectricProd(Weapon):
    def __init__(self):
        super().__init__(88, 18, 5)

    def use(self, target):
        target.take_damage(self.damage,self.energy)


class MegaMagnet(Weapon):
    def __init__(self):
        super().__init__(92, 10, 3)

    def use(self, target):
        target.take_damage(self.damage,self.energy)


class KalmanMissile(Weapon):
    def __init__(self):
        super().__init__(120, 20, 1)

    def use(self, target):
        target.take_damage(self.damage,self.energy)


class Shield:
    def __init__(self, energy, save_percentage, resources):
        self.energy = energy
        self.save_percentage = save_percentage
        self.resources = resources


class EnergyProjectedBarrierGun(Shield):
    def __init__(self):
        super().__init__(20, 0.4, float('inf'))


class SelectivePermeability(Shield):
    def __init__(self):
        super().__init__(50, 0.9, 2)


class LaserBlasters(Weapon):
    def __init__(self):
        super().__init__(40, 8, float('inf'))

    def use(self, target):
        target.take_damage(self.damage,self.energy)


class PlasmaGrenades(Weapon):
    def __init__(self):
        super().__init__(70, 15, 5)

    def use(self, target):
        target.take_damage(self.damage,self.energy)


class SonicResonanceCannon(Weapon):
    def __init__(self):
        super().__init__(100, 25, 2)

    def use(self, target):
        target.take_damage(self.damage,self.energy)


class EnergyNetTrap(Shield):
    def __init__(self):
        super().__init__(30, 0.6, float('inf'))


class QuantumDeflector(Shield):
    def __init__(self):
        super().__init__(60, 0.8, 3)


def play_game():
    gru = Gru("Gru")
    vector = Vector("Vector")
    round_num = 1

    while not gru.is_defeated() and not vector.is_defeated():
        print(f"Round {round_num}")
        print(f"{gru.name}: Health = {gru.health}, Energy = {gru.energy}")
        print(f"{vector.name}: Health = {vector.health}, Energy = {vector.energy}")
        print()

        # Gru's turn
        print(f"{gru.name}'s turn:")
        gru.attack(vector)
        if vector.is_defeated():
            break
        gru.defend()
        print()

        # Vector's turn
        print(f"{vector.name}'s turn:")
        vector.attack(gru)
        if gru.is_defeated():
            break
        vector.defend()
        print()

        round_num += 1

    if gru.is_defeated() and vector.is_defeated():
        print("It's a tie!")
    elif gru.is_defeated():
        print(f"{vector.name} wins!")
    else:
        print(f"{gru.name} wins!")


play_game()