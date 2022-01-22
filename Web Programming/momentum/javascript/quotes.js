const quotes = [
  {
    quote: "quotation test 1",
    author: "author test for quotes",
  },
  {
    quote: "quotatin test 2",
    author: "author test for quote 2",
  },
];

const quote = document.querySelector("#quote span:first-child");
const author = document.querySelector("#quote span:last-child");
const my_quote = quotes[Math.floor(Math.random() * quotes.length)];
quote.innerText = my_quote.quote;
author.innerText = my_quote.author;
