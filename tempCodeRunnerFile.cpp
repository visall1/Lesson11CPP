 ofstream fout("contacts2.txt", ios::out|ios::binary);
    if(fout){
        Contact c("Dara","012365478",2000,12,21);
        c.writeToFile(fout);
        fout.close();
    } 