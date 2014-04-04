package laborki.paradygmaty;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Lab7 {

    public static void main(String[] args) throws IOException {

	boolean wybor = true;
	int decyzja = 1;

	List<Operacje_good> dane_good = new ArrayList<Operacje_good>();
	List<Operacje_bad> dane_bad = new ArrayList<Operacje_bad>();

	do {
	    System.out.println("Wprowazanie danych:");
	    System.out.println("\nBezparametrowy good:");
	    Operacje_good bezparametrowy_good = new Operacje_good();
	    System.out.println("\nParametrowy good:");
	    Operacje_good parametrowy_good = new Operacje_good(4, 4, 1);

	    System.out.println("\nBezparametrowy bad:");
	    Operacje_bad bezparametrowy_bad = new Operacje_bad();
	    System.out.println("\nParametrowy bad:");
	    Operacje_bad parametrowy_bad = new Operacje_bad(3, 3, 3);

	    dane_good.add(bezparametrowy_good);
	    dane_good.add(parametrowy_good);

	    dane_bad.add(bezparametrowy_bad);
	    dane_bad.add(parametrowy_bad);

	    System.out.println("\nLista obiektow klasy operacje_good");
	    for (int i = 0; i < dane_good.size(); i++) {
		dane_good.get(i).oblicz_d();
		dane_good.get(i).oblicz_pierwiastki();
		dane_good.get(i).dodaj();
		dane_good.get(i).odejmij();
		dane_good.get(i).iloczyn();
		dane_good.get(i).podziel();
		System.out.println("");
		dane_good.get(i).wyswietl();
	    }

	    System.out.println("\nLista obiektow klasy operacje_bad");
	    for (int i = 0; i < dane_bad.size(); i++) {
		dane_bad.get(i).oblicz_d();
		dane_bad.get(i).dodaj();
		dane_bad.get(i).odejmij();
		dane_bad.get(i).iloczyn();
		dane_bad.get(i).podziel();
		System.out.println("");
		dane_bad.get(i).wyswietl();
	    }

	    System.out.println("\nCzyszczenie list.");
	    dane_good.removeAll(dane_good);
	    dane_bad.removeAll(dane_bad);

	    System.out
		    .println("\nCzy liczyc dalej? Wcisnij 1. (0 (zero) konczy obliczenia)");
	    BufferedReader bufor_koniec = new BufferedReader(
		    new InputStreamReader(System.in), 1);
	    decyzja = Integer.parseInt(bufor_koniec.readLine());
	    if (decyzja == 0) {
		System.out.println("Zakonczono program.");
		wybor = false;
	    } else {
		continue;
	    }

	} while (wybor == true);

    }
}