int n,q;
cin >> n >> q;
vector< vector<int> > a(n);

// input each array
for (int i=0;i<n;i++) {
    int k;
    cin >> k;

    for (int j=0;j<k;j++) {
        int data;
        cin >> data;
        a[i].push_back(data);
    }
}

// do the queries
for (int i=0;i<q;i++) {
    int x,y;
    cin >> x >> y;
    cout << a[x][y] << endl;
}
