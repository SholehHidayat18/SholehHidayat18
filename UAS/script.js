const txtelement = ['WELCOME TO ATENG STORE'];
let count = 0;
let txtindex = 0;
let currentxt = '';
let words = '';

(function ngetik() {

    if (count == txtelement.length) {
        count = 0;
    }
    currentxt = txtelement[count];

    words = currentxt.slice(0, ++txtindex);
    document.querySelector('.efek-ngetik').textContent = words;

    if (words.length == currentxt.length) {
        count++;
        txtindex = 0;
    }
    setTimeout(ngetik, 400);
})
(function addBarang() {
    var input = document.querySelector("input[name=barang]");
    dataBarang.push(input.value);
    showBarang();
})