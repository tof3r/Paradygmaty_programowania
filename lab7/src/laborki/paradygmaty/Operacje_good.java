package laborki.paradygmaty;

import java.io.*;
import java.util.Vector;
import static java.lang.Math.*;

public class Operacje_good extends Operacje {

    Vector<Object> tab = new Vector<Object>();
    float d, x1r, x2r, sr, rr, ilr, irr, x1u, x2u, su, ru, ilu, iru;

    public Operacje_good() throws IOException {
	int a = 0;
	int b = 0;
	int c = 0;
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
	try {
	    BufferedReader bufor_a = new BufferedReader(new InputStreamReader(
		    System.in), 1);
	    a = Integer.parseInt(bufor_a.readLine());
	} catch (IOException e) {
	    System.out.println("Blad odczytu z klawiatury" + e.toString());
	}
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

    public Operacje_good(int a, int b, int c) {
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

    public int oblicz_pierwiastki() {
	int pierw = 0;

	if (((int) tab.get(0) == 0) && ((int) tab.get(1) != 0)) {
	    x1r = -(float) (int) tab.get(2) / (float) (int) tab.get(1);
	    return pierw = 1;
	}

	if (((int) tab.get(0) == 0) && ((int) tab.get(1) == 0)
		&& ((int) tab.get(2) != 0)) {
	    return pierw = 2;
	}

	if (((int) tab.get(0) == 0) && ((int) tab.get(1) == 0)
		&& ((int) tab.get(2) == 0)) {
	    return pierw = 3;
	}

	if ((int) tab.get(0) != 0) {
	    oblicz_d();
	    if (d > 0) {
		x1r = (float) (((-(int) tab.get(1)) - sqrt(d)) / (2 * (float) (int) tab
			.get(0)));
		x2r = (float) (((-(int) tab.get(1)) + sqrt(d)) / (2 * (float) (int) tab
			.get(0)));
		irr = (x1r / x2r);
		return pierw = 4;
	    }
	    if (d == 0) {
		x1r = (float) (-(int) tab.get(1))
			/ (float) (2 * (int) tab.get(0));
		return pierw = 5;
	    }
	    if (d < 0) {
		x1r = (float) (-(int) tab.get(1)) / (2 * (int) tab.get(0));
		x2r = (float) (-(int) tab.get(1)) / (2 * (int) tab.get(0));
		x1u = (float) (-sqrt(abs((float) d)) / (2 * (float) (int) tab
			.get(0)));
		x2u = (float) (sqrt(abs((float) d)) / (2 * (float) (int) tab
			.get(0)));
		irr = (x1r * x2r + x1u * x2u) / ((x2r * x2r) + (x2u * x2u));
		iru = (x2r * x1u - x1r * x2u) / ((x2r * x2r) + (x2u * x2u));

		return pierw = 6;
	    }
	}
	return pierw;

    }

    public void dodaj() {
	if (d > 0) {
	    sr = (x1r) + (x2r);
	}
	if (d < 0) {
	    sr = (x1r) + (x2r);
	    su = (x1u) + (x2u);
	}
    }

    public void odejmij() {
	if (d > 0) {
	    rr = (x1r) - (x2r);
	}
	if (d < 0) {
	    rr = (x1r) - (x2r);
	    ru = (x1u) - (x2u);
	}
    }

    public void iloczyn() {
	if (d > 0) {
	    ilr = (x1r) * (x2r);
	}
	if (d < 0) {
	    ilr = (x1r) * (x2r);
	    ilu = (x1u) * (x2u);
	}
    }

    public void podziel() {
	if (d > 0) {
	    irr = x1r / x2r;
	}
	if (d < 0) {
	    irr = (x1r * x2r + x1u * x2u) / ((x2r * x2r) + (x2u * x2u));
	    iru = (x2r * x1u - x1r * x2u) / ((x2r * x2r) + (x2u * x2u));
	}
    }

    public void wyswietl() {
	int y = oblicz_pierwiastki();
	switch (y) {
	case 1:
	    System.out.println("x1r = " + x1r);
	    break;
	case 2:
	    System.out.println("Rownanie sprzeczne");
	    break;
	case 3:
	    System.out.println("Rownanie nieoznaczone");
	    break;
	case 4:
	    System.out.println("Delta =" + d);
	    System.out.println("x1r = " + x1r);
	    System.out.println("x2r = " + x2r);
	    System.out.println("sr = " + sr);
	    System.out.println("rr = " + rr);
	    System.out.println("ilr = " + ilr);
	    System.out.println("irr = " + irr);
	    break;
	case 5:
	    System.out.println("Delta = " + d);
	    System.out.println("x1r = " + x1r);
	    break;
	case 6:
	    System.out.println("Delta = " + d);
	    System.out.println("x1r = " + x1r);
	    System.out.println("x1u = " + x1u + "i");
	    System.out.println("x2r = " + x2r);
	    System.out.println("x2u = " + x2u + "i");
	    System.out.println("sr = " + sr);
	    System.out.println("su = " + su);
	    System.out.println("rr = " + rr);
	    System.out.println("ru = " + ru);
	    System.out.println("ilr = " + ilr);
	    System.out.println("ilu = " + ilu);
	    System.out.println("irr = " + irr);
	    System.out.println("iru = " + iru);
	    break;
	}
    }
}
