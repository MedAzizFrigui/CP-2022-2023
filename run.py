import os 

import os


members = [
    "Jlejla Habib",
    "Frigui Mohamed Aziz",
    "Frigui Firas",
    "Jarray Saif Eddine",
    "Lajmi Yessmine",
    "Sdiri Chedha",
    "Baalouch Mouheb",
    "Belkacem Mohamed Amir",
    "Neifer Dhia",
    "Hamdi Massoued",
    "Gazzeh Mohamed",
    "Mbarki Marwen",
    "Sallemi Wassim",
    "Ben Aicha Iyed",
    "Ben Mustapha Riadh",
    "Hamdani Dhie",
    "Baccari Ala",
    "Abidi Aymen"
]

for member in members:
    os.chdir(member)
    os.chdir('Mathematics')
    with open('.gitkeep','a') as file:
        print('file .gitkeep created')
    os.chdir('..')
    os.chdir('Straight-Forward')
    with open('.gitkeep','a') as file:
        print('file .gitkeep created')
    os.chdir('..')
    os.chdir('..')