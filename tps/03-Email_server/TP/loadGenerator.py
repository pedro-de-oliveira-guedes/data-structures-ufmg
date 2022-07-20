import os
import random

def generateFile(fileName: str, messagesPerUser: int):
    outputFile = open(fileName, "w")

    numberOfUsers = 5
    hashTableSize = int(numberOfUsers*1.3)
    outputFile.write(str(hashTableSize) + "\n")

    userIds = random.sample(range(numberOfUsers), numberOfUsers)
    emailIds = random.sample(range(numberOfUsers * messagesPerUser), numberOfUsers * messagesPerUser)

    smallMessage = {
    "size": "15",
    "content": " Bom dia, meu amigo! Tudo bom? Eu estou muito muito bem, obrigado por me perguntar."
    }
    mediumMessage = {
    "size": "100",
    "content": " descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente descontingenciamento compartimentalizacao superdimensionamento desproporcionalidade circunstanciadamente"
    }
    bigMessage = {
    "size": "200",
    "content": " aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona aaapiperidinoetoxicarbometoxibenzofenona"
    }
    mailMessages = [smallMessage, mediumMessage, bigMessage]

    serverDict = {}

    for userId in userIds:
        serverDict[userId] = []

    currentEmailIdx = 0
    for userId in userIds:
        for i in range(messagesPerUser):
            serverDict[userId].append(emailIds[currentEmailIdx]) 
            currentEmailIdx += 1

    for key in serverDict:
        for emailId in serverDict[key]:
            messageIdx = random.randint(0, 2)
            outputFile.write("ENTREGA " + str(key) + " " + str(emailId) + " " + mailMessages[0]["size"] + mailMessages[0]["content"])
            outputFile.write("\n")

    randomEmailIdx = 0
    for key in serverDict:
        for i in range(0, int(messagesPerUser/2.0)):
            randomEmailIdx = random.randint(0, messagesPerUser-1)
            outputFile.write("CONSULTA " + str(key) + " " + str(serverDict[key][randomEmailIdx]))
            outputFile.write("\n")

    randomEmailIdx = 0
    for key in serverDict:
        for i in range(0, int(messagesPerUser/2.0)):
            randomEmailIdx = random.randint(0, messagesPerUser-1)
            outputFile.write("APAGA " + str(key) + " " + str(serverDict[key][randomEmailIdx]))
            outputFile.write("\n")

messagesPerUser = [200000, 400000, 600000, 800000, 1000000]
for num in range(5):
    generateFile(f'entrada_{num + 1}.out', messagesPerUser[num])