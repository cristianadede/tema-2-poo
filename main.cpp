#include <iostream>

using namespace std;
class multime_pereche;
class stiva_pereche;
class coada_pereche;
class pereche
{
    protected:
    int nr1;
    int nr2;
    public:

    pereche(const pereche&);//const de copiere
    pereche(int,int);//const de initializare cu un nr dat
    ~pereche();//destructor
    pereche& operator=(const pereche &);
    friend ostream& operator<<(ostream&, const pereche&);
    friend istream& operator>>(istream&, pereche&);
    friend class multime_pereche;
    friend class stiva_pereche;
    friend class coada_pereche;

};

class multime_pereche
{
    protected:
    int n;
    pereche*p;
    public:
    multime_pereche();
    multime_pereche(const multime_pereche&);//const de copiere
    multime_pereche(int,pereche*);//const de initializare cu un nr dat
    virtual~multime_pereche();//destructor
    multime_pereche& operator=(const multime_pereche &);
    virtual void adaugare_pereche (int,int,int);
    virtual void stergere_pereche (int);
    friend ostream& operator<<(ostream&, const multime_pereche&);
    friend istream& operator>>(istream&, multime_pereche&);
    void citire();
    void afisare();
    void simulare_stiva();
};



pereche::pereche(int x=0, int y=0) //constructor de initializare
{
    nr1=x; nr2=y;
}
pereche::pereche(const pereche&ob) //constructor de copiere
{
    nr1=ob.nr1;
    nr2=ob.nr2;
}
pereche::~pereche()//destructor
{
   // cout<<"Distrugere obiect";
}
pereche& pereche :: operator=(const pereche &ob) //suprascriere operator de atribuire
{
    if(this!=&ob)
    {
        nr1=ob.nr1;
        nr2=ob.nr2;
    }
    return*this;
}
ostream& operator<<(ostream& out, const pereche& ob){

    out<<ob.nr1<<ob.nr2;

 return out;

};

istream& operator>>(istream& in, pereche& ob){

    in>>ob.nr1>>ob.nr2;

 return in;

};

multime_pereche::multime_pereche()
{
    n=0;
    p=new pereche[n];
}
multime_pereche::multime_pereche(const multime_pereche&ob) //constructor de copiere
{
    n=ob.n;
    p=new pereche[n];
    for(int i=0;i<n;i++)
       {
           p[i].nr1=ob.p->nr1;
           p[i].nr2=ob.p->nr2;
       }
}

multime_pereche::multime_pereche(int x,pereche*nr)//initializare cu un nr dat pe toate componentele
{
    n=x;
    p=new pereche[n];
    for(int i=0;i<n;i++)
       {
           p[i].nr1=nr[i].nr1;
           p[i].nr2=nr[i].nr2;
       }
}
multime_pereche::~multime_pereche() //destructor
{
    delete []p;
}

multime_pereche& multime_pereche :: operator=(const multime_pereche &ob) //suprascriere operator de atribuire
{
    if(this!=&ob)
    {
        delete [] p;
        n=ob.n;
        p=new pereche [n];
        for(int i=0;i<n;i++)
        {
           p[i].nr1=ob.p->nr1;
           p[i].nr2=ob.p->nr2;
        }
    }
    return*this;
}
ostream& operator<<(ostream& out, const multime_pereche& ob){

 for(int i=0;i<ob.n;i++)
    out<<ob.p[i];
 return out;

};

istream& operator>>(istream& in, multime_pereche& ob){

   for(int i=0;i<ob.n;i++)
    in>>ob.p[i];

 return in;

};

void multime_pereche::adaugare_pereche(int k,int val1,int val2)
{
    try
    {
        if(k>n)
            throw k;
    }
    catch(int x){cout<<endl<<"Pozitia nu exista";}
    pereche*cop_p;int i;
    cop_p=new pereche[n+1];
    for(i=0;i<n;i++)
        cop_p[i]=p[i];
    delete []p;
    for(int i=n-1; i>=k ; i --)
    cop_p[i+1] = cop_p[i];
cop_p[k].nr1 = val1;
cop_p[k].nr2 = val2;
n++;
p=new pereche[n];
    for(i=0;i<n;i++)
        p[i]=cop_p[i];

}

void multime_pereche::stergere_pereche(int k)
{
    try
    {
        if(n==0)
            throw n;
    }
    catch(int x){cout<<"Multimea de perechi este goala";}
    try
    {
        if(k>n)
            throw k;
    }
    catch(int x){cout<<endl<<"Pozitia nu exista";}
    if(n!=0)
   {
    int i;
     pereche*cop_p;
    cop_p=new pereche[n-1];
    for(int i=k ; i<n-1; i++)
    p[i] = p[i+1];
    n--;
    for(i=0;i<n;i++)
        cop_p[i]=p[i];
    delete []p;
    p=new pereche[n];
    for(i=0;i<n;i++)
        p[i]=cop_p[i];
   }
}

void multime_pereche::citire() //functie(metoda) de citire
{
    cout<<"Introduceti nr de perechi: ";
    cin>>n;
    p=new pereche[n];
     for(int i=0;i<n;i++)
     {    cout<<"Intoruceti perechea "<<i<<endl;
          cin>>p[i];
     }

}

void multime_pereche::afisare()//functie de afiare
{
    for(int i=0;i<n;i++)
    {
        cout<<"Perechea "<<i<<" este : ";
        cout<<p[i].nr1<<' '<<p[i].nr2;
        cout<<endl;
    }


}
class stiva_pereche : public multime_pereche
{
public:
    stiva_pereche():multime_pereche()
    {
        n=1;
        p=new pereche[n];
    }
    stiva_pereche(int x,pereche*nr) : multime_pereche(x,nr)
    {
            n=x;
        p=new pereche[n];
        for(int i=0;i<n;i++)
        {
           p[i].nr1=nr[i].nr1;
           p[i].nr2=nr[i].nr2;
        }
    }
    stiva_pereche(const stiva_pereche&ob) : multime_pereche(ob)
    {

    n=ob.n;
    p=new pereche[n];
    for(int i=0;i<n;i++)
       {
           p[i].nr1=ob.p->nr1;
           p[i].nr2=ob.p->nr2;
       }

    }
    stiva_pereche& operator=(const stiva_pereche &ob)
    {
        if(this!=&ob)
        {
            this->multime_pereche::operator=(ob);
        }
    return*this;
    }
    ~stiva_pereche(){delete []p;}
    friend ostream& operator<<(ostream&, const stiva_pereche&);
    friend istream& operator>>(istream&, stiva_pereche&);
    void adaugare_pereche(int,int);
    void stergere_pereche();
};
ostream& operator<<(ostream& out, const stiva_pereche& ob){

 for(int i=0;i<ob.n;i++)
    out<<ob.p[i];
 return out;

};

istream& operator>>(istream& in, stiva_pereche& ob){

   for(int i=0;i<ob.n;i++)
    in>>ob.p[i];

 return in;

};

void stiva_pereche::adaugare_pereche(int val1,int val2)
{
    int k=0; int i;
    pereche*cop_p;
    cop_p=new pereche[n+1];
    for(i=0;i<n;i++)
        cop_p[i]=p[i];
    delete []p;
    for(int i=n-1; i>=k ; i --)
    cop_p[i+1] = cop_p[i];
cop_p[k].nr1 = val1;
cop_p[k].nr2 = val2;
n++;
p=new pereche[n];
    for(i=0;i<n;i++)
        p[i]=cop_p[i];

}

void stiva_pereche::stergere_pereche()
{     try
    {
        if(n==0)
            throw n;
    }
    catch(int x){cout<<"Multimea de perechi este goala";}

    if(n!=0)
    {
     int k=0;
    int i;
     pereche*cop_p;
    cop_p=new pereche[n-1];
    for(int i=k ; i<n-1; i++)
    p[i] = p[i+1];
    n--;
    for(i=0;i<n;i++)
        cop_p[i]=p[i];
    delete []p;
    p=new pereche[n];
    for(i=0;i<n;i++)
        p[i]=cop_p[i];
    }
}


class coada_pereche : public multime_pereche
{
public:
    coada_pereche():multime_pereche()
    {
        n=1;
        p=new pereche[n];
    }
    coada_pereche(int x,pereche*nr) : multime_pereche(x,nr)
    {
            n=x;
        p=new pereche[n];
        for(int i=0;i<n;i++)
        {
           p[i].nr1=nr[i].nr1;
           p[i].nr2=nr[i].nr2;
        }
    }
    coada_pereche(const coada_pereche&ob) : multime_pereche(ob)
    {

    n=ob.n;
    p=new pereche[n];
    for(int i=0;i<n;i++)
       {
           p[i].nr1=ob.p->nr1;
           p[i].nr2=ob.p->nr2;
       }

    }
    coada_pereche& operator=(const coada_pereche &ob)
    {
        if(this!=&ob)
        {
            this->multime_pereche::operator=(ob);
        }
    return*this;
    }
    ~coada_pereche(){delete []p;}
    friend ostream& operator<<(ostream&, const coada_pereche&);
    friend istream& operator>>(istream&, coada_pereche&);
    void adaugare_pereche(int,int);
    void stergere_pereche();
};
ostream& operator<<(ostream& out, const coada_pereche& ob){

 for(int i=0;i<ob.n;i++)
    out<<ob.p[i];
 return out;

};

istream& operator>>(istream& in, coada_pereche& ob){

   for(int i=0;i<ob.n;i++)
    in>>ob.p[i];

 return in;

};

void coada_pereche::adaugare_pereche(int val1,int val2)
{  int k=n; int i;
    pereche*cop_p;
    cop_p=new pereche[n+1];
    for(i=0;i<n;i++)
        cop_p[i]=p[i];
    delete []p;
    for(int i=n-1; i>=k ; i --)
    cop_p[i+1] = cop_p[i];
cop_p[k].nr1 = val1;
cop_p[k].nr2 = val2;
n++;
p=new pereche[n];
    for(i=0;i<n;i++)
        p[i]=cop_p[i];

}

void coada_pereche::stergere_pereche()
{
       try
    {
        if(n==0)
            throw n;
    }
    catch(int x){cout<<"Multimea de perechi este goala";}
     if(n!=0)
     {
     int k=0;
    int i;
     pereche*cop_p;
    cop_p=new pereche[n-1];
    for(int i=k ; i<n-1; i++)
    p[i] = p[i+1];
    n--;
    for(i=0;i<n;i++)
        cop_p[i]=p[i];
    delete []p;
    p=new pereche[n];
    for(i=0;i<n;i++)
        p[i]=cop_p[i];
     }
}

void multime_pereche::simulare_stiva()
{   coada_pereche c1,c2; pereche per;
    c1.stergere_pereche();
    c2.stergere_pereche(); int val1,val2;
    cout<<"Nr de perechi pe care il inseram in stiva este: ";
    int nr; cin>>nr;
    while(nr)
    {   cout<<"Inserati o pereche: ";
        cout<<endl<<"nr1: ";
        cin>>val1;
        cout<<"nr2: ";
        cin>>val2;
        c1.adaugare_pereche(val1,val2);
        while(c1.n!=1)
        {
            per=c1.p[0];
            c1.stergere_pereche();
            c2.adaugare_pereche(per.nr1,per.nr2);
        }
        while(c2.n)
        {
            per=c2.p[0];
            c2.stergere_pereche();
            c1.adaugare_pereche(per.nr1,per.nr2);
        }
        nr--;
    }
    cout<<endl<<"Stiva realizata cu ajutorul a doua cozi este: ";
    c1.afisare();
}
int main()
{   multime_pereche*perechi; int i;
    cout<<"Introduceti nr de multimi de perechi: ";
    int n; cin>>n;
    perechi=new multime_pereche[n];
    for(i=0;i<n;i++)
    {   cout<<"Multimea de perechi numarul "<<i<<endl;
        perechi[i].citire();
    }
    for(i=0;i<n;i++)
    {   cout<<"Multimea de perechi numarul "<<i<<endl;
        perechi[i].afisare(); cout<<endl;
    }

    multime_pereche x;
    x.simulare_stiva(); int ok,m,q,o;
    multime_pereche a; a.stergere_pereche(0); stiva_pereche b; b.stergere_pereche(); coada_pereche c; c.stergere_pereche();
    do{
  cout<<endl<<"Tastati unul din numerele de mai jos: "<<endl;
  cout<<"0 - Oprire"<<endl;
  cout<<"1 - Inserare o pereche intr-o multime"<<endl;
  cout<<"2 - Inserare o pereche in coada"<<endl;
  cout<<"3 - Inserare o pereche in stiva"<<endl;
  cout<<"4 - Stergerea unei perechi din multime"<<endl;
  cout<<"5 - Stergerea unei perechi din stiva"<<endl;
  cout<<"6 - Stergerea unei perechi din coada"<<endl;
  cout<<"7 - Citirea unei multimi de perechi"<<endl;
  cout<<"8 - Afisare multime de perechi"<<endl;
  cout<<"9 - Afisarea stiva de perechi"<<endl;
  cout<<"10 - Afisarea coada de perechi"<<endl;
  cin>>ok;

   switch(ok){
      case 0:
      cout<<"stop";
      break;
      case 1:
        { cout<<"Introduceti o pozitie pentru inserare: "<<endl; cin>>m;cout<<"Introduceti o pereche pentru inserare: ";cin>>q>>o; a.adaugare_pereche(m,n,o);}
        break;
      case 2:
        { cout<<endl<<"Introduceti o pereche pentru inserare: "<<endl;cin>>q>>o; c.adaugare_pereche(n,o);}
        break;
      case 3:
        { cout<<endl<<"Introduceti o pereche pentru inserare: "<<endl;cin>>q>>o; b.adaugare_pereche(n,o);}
        break;
      case 4:
        { cout<<"Introduceti o pozitie pentru stergere "<<endl; cin>>m; a.stergere_pereche(m);}
        break;
      case 5:
        { cout<<"Se sterge o pereche din stiva: "<<endl; b.stergere_pereche();}
        break;
      case 6:
        { cout<<"Se sterge o pereche din coada"<<endl; c.stergere_pereche();}
        break;
      case 7:
        { a.citire();}
        break;
      case 8:
        { cout<<"Multimea curenta este: "<<endl; a.afisare();}
        break;
      case 9:
        { cout<<"Stiva curenta este: "<<endl; b.afisare();}
        break;
      case 10:
        { cout<<"Coada curenta este: "<<endl; c.afisare();}
  }
  }while(ok!=0);

    return 0;
}
