import UIKit

struct IceCream {
    var flavor: String
    var weight: Int
}

func weighting(_ iceCreams: [IceCream]) -> Int {
    let sum = getTheSum(iceCreams: iceCreams)
    var random = Int.random(in: 0 ... sum)
    
    for arrayPos in 0 ... iceCreams.count - 1 {
        if random > 0 {
            random = random - iceCreams[arrayPos].weight
        }
        
        if random <= 0 {
            print(arrayPos)
            return arrayPos
        }
    }
    //If catchs here, has a error
    return -1
}

func getTheSum(iceCreams: [IceCream]) -> Int {
    var totalWeight: Int = 0
    for i in 0 ... iceCreams.count - 1 {
        totalWeight += iceCreams[i].weight
    }
    return totalWeight
}

var iceCreamArray: [IceCream] = [IceCream(flavor: "Vanilla", weight: 15), IceCream(flavor: "Strawberry", weight: 25), IceCream(flavor: "Chocolate", weight: 55), IceCream(flavor: "Cookies and Cream", weight: 5)]

var results: [Int] = []

for _ in 0 ... iceCreamArray.count - 1 {
    results.append(0)
}

for _ in 0 ... 99 {
    results[weighting(iceCreamArray)] += 1
}

print(results)
