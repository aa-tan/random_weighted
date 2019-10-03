const LIMIT = 100;

const weights = {
  'Vanilla': 15,
  'Strawberry': 25,
  'Chocolate': 55,
  'Cookies and Cream': 5
};

function weight(sum) {
  let random = Math.floor(Math.random() * sum) + 1;
  for (let flavor in weights) {
    random -= weights[flavor];
    if (random <= 0) return flavor;
  }
  return 'Should not reach here.';
}

let results = {};

let sum = 0;
for (let flavor in weights) {
  sum += weights[flavor];
  results[flavor] = 0;
}

for (let i = 0; i < LIMIT; i++) {
  results[weight(sum)] += 1;
}

console.log(results);
