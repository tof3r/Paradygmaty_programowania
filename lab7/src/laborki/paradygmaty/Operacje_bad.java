package laborki.paradygmaty;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class Operacje_bad extends Operacje {
    Vector<Object> tab = new Vector<Object>();
    float d, x1r, x2r, sr, rr, ilr, irr, x1u, x2u, su, ru, ilu, iru;

    public Operacje_bad() throws IOException {
	int a, b, c;
	d = 0;
	x1r = 0;
	x2r = 0;
	sr = 0;
	rr = 0;
	ilr = 0;
	irr = 0;
	x1u = 0;
	x2u = 0;
	su = 0;
	ru = 0;
	ilu = 0;
	iru = 0;

	System.out.println("Wprowadz a:");
	BufferedReader bufor_a = new BufferedReader(new InputStreamReader(
		System.in), 1);
	a = Integer.parseInt(bufor_a.readLine());
	System.out.println("Wprowadz b:");
	BufferedReader bufor_b = new BufferedReader(new InputStreamReader(
		System.in), 1);
	b = Integer.parseInt(bufor_b.readLine());
	System.out.println("Wprowadz c:");
	BufferedReader bufor_c = new BufferedReader(new InputStreamReader(
		System.in), 1);
	c = Integer.parseInt(bufor_c.readLine());

	tab.add(a);
	tab.add(b);
	tab.add(c);

	System.out.println("Wartosci wprowadzone do wektora:");
	for (int i = 0; i < tab.size(); i++) {
	    System.out.println(tab.get(i));
	}
    }

    public Operacje_bad(int a, int b, int c) {
	d = 0;
	x1r = 0;
	x2r = 0;
	sr = 0;
	rr = 0;
	ilr = 0;
	irr = 0;
	x1u = 0;
	x2u = 0;
	su = 0;
	ru = 0;
	ilu = 0;
	iru = 0;

	tab.add(a);
	tab.add(b);
	tab.add(c);

	System.out.println("Wartosci wprowadzone do wektora:");
	for (int i = 0; i < tab.size(); i++) {
	    System.out.println(tab.get(i));
	}
    }

    public void oblicz_d() {
	d = (int) tab.get(1) * (int) tab.get(1) - 4 * (int) tab.get(0)
		* (int) tab.get(2);
    }

    public void dodaj() {
	if (d > 0) {
	    sr = (x1r) + (x2r);
	}
	if (d < 0) {
	    sr = (x1r) + (x1u);
	    su = (x2r) + (x2u);
	}
    }

    public void odejmij() {
	if (d > 0) {
	    rr = (x1r) - (x2r);
	}
	if (d < 0) {
	    rr = (x1r) - (x1u);
	    ru = (x2r) - (x2u);
	}
    }

    public void iloczyn() {
	if (d > 0) {
	    ilr = (x1r) * (x2r);
	}
	if (d < 0) {
	    ilr = (x1r) * (x1u);
	    ilu = (x2r) * (x2u);
	}
    }

    public void podziel() {
	if (d > 0) {
	    irr = x1r / x2r;
	}
	if (d < 0) {
	    irr = (x1r) / (x1u);
	    iru = (x2r) / (x2u);
	}
    }

    public void wyswietl() {
	System.out.println("Delta = " + d);
	System.out.println("sr= " + sr);
	System.out.println("su = " + su);
	System.out.println("rr = " + rr);
	System.out.println("ru = " + ru);
	System.out.println("ilr = " + ilr);
	System.out.println("ilu = " + ilu);
	System.out.println("irr = " + irr);
	System.out.println("iru = " + iru);
    }
}
