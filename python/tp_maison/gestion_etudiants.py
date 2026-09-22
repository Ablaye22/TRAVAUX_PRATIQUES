ID = 0
etudiants = []
def generer_id():
    global ID
    ID += 1
    return ID

def ajouter_etudiant():
    nom = input("Nom : ")
    prenom = input("Prénom : ")
    age = int(input("Age : "))
    if age < 0 :
        print("L'age ne peux pas etre negatif : ")
        return 
    etudiant = {
        "id" : generer_id(),
        "nom" : nom,
        "prenom" : prenom,
        "age" : age
    }
    etudiants.append(etudiant)

def afficher_etudiants():
    if len(etudiants) == 0:
        print("La liste d'étudiants est vide ")
        return
    print("")
    print("===== ETUDIANTS =====")
    print("")
    for etudiant in etudiants:
        print(f"ID : {etudiant['id']}")
        print(f"Prénom : {etudiant['prenom']}")
        print(f"Nom : {etudiant['nom']}")
        print(f"Age : {etudiant['age']}")
        print("")
        print("---------------------")
        print("")

def rechercher_etudiant():
    nom = input("Nom d'etudiant à rechercher : ")
    for etudiant in etudiants:
        if etudiant['nom'].lower() == nom.lower():
            print("")
            print(f"ID : {etudiant['id']}")
            print(f"Prénom : {etudiant['prenom']}")
            print(f"Nom : {etudiant['nom']}")
            print(f"Age : {etudiant['age']}")
            print("")
            return 
    print("Aucun étudiant n'est trouvé.")

def supprimer_etudiant():
    ID = int(input("ID de l'étudiant à supprimer : "))
    for etudiant in etudiants:
        if etudiant['id'] == ID:
            etudiants.remove(etudiant)
            print("Etudiant supprimer avec succès")
            return 
    print("Aucun étudiant n'est trouvé.")

def sauvegarder():
    fichier = open("etudiants.txt","w")
    for etudiant in etudiants:
        fichier.write(f"{etudiant['id']};{etudiant['nom']};{etudiant['prenom']};{etudiant['age']}\n")
    fichier.close()
    print("Les étudiant ont été sauvegarder avec succès")

def charger():
    fichier = open("etudiants.txt","r")
    etudiants.clear()
    for line in fichier:
        element = line.split(";")
        etudiant ={
            "id" : element[0],
            "prenom" : element[2] ,
            "nom" : element[1],
            "age" : element[3]
        }
        etudiants.append(etudiant)
    fichier.close()

def menu():
    print("")
    print("===== GESTION ETUDIANTS =====")
    print("")
    print("1. Ajouter un étudiant")
    print("2. Afficher les étudiants")
    print("3. Rechercher un étudiant")
    print("4. Supprimer un étudiant")
    print("5. Sauvegarder")
    print("6. Charger")
    print("7. Quitter")
    print("")

if __name__ == "__main__":
    while True:
        menu()
        choix = int(input("Votre Choix : "))
        match choix:
            case 1:
                ajouter_etudiant()
            case 2:
                afficher_etudiants()
            case 3:
                rechercher_etudiant()
            case 4:
                supprimer_etudiant()
            case 5:
                sauvegarder()
            case 6:
                charger()
            case 7:
                sauvegarder()
                break
            case _:
                print("")
                print("Choix invalide")
