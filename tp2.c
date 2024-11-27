#include <stdio.h>

char *ChargerChaine(int N) {
char *chaine = (char *)malloc((N + 1) * sizeof(char));
if (chaine == NULL) {
printf("Erreur d'allocation mémoire.\n");
exit(1);
}
printf("Entrez une chaine de %d caracteres: ", N);
scanf("%s", chaine);
return chaine;
}

int Longueur(char *ch) {
int len = 0;
while (ch[len] != '\0') {
len++;
}
return len;
}

void ChargerTab(char *p, char Tab[]) {
int i = 0;
while (p[i] != '\0') {
Tab[i] = p[i];
i++;
}
Tab[i] = '\0';
}

void InverserTab(char Tab[], char T[], int m) {
for (int i = 0; i < m; i++) {
T[i] = Tab[m - i - 1];
}
T[m] = '\0';
}

void AfficherTab(char Tab[], int m) {
for (int i = 0; i < m; i++) {
printf("%c", Tab[i]);
}
printf("\n");
}

int main() {
int N;
printf("Entrez la taille de la chaine: ");
scanf("%d", &N);


char *chaine = ChargerChaine(N);


int longueur = Longueur(chaine);
printf("La longueur de la chaine est: %d\n", longueur);


char Tab[longueur + 1]; 
ChargerTab(chaine, Tab);


char Inverse[longueur + 1]; 
InverserTab(Tab, Inverse, longueur);


printf("Chaine originale: ");
AfficherTab(Tab, longueur);

printf("Chaine inversee: ");
AfficherTab(Inverse, longueur);


free(chaine);

return 0;
}
