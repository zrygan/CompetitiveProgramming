package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

/*
 * Naive Algorithm
 * n = 4096
 * t = 8m27.5939443s
 *
 * Naive Algorithm with Spacial Locality
 * n = 4096
 * t = 1m10.3292929s
 */
func MatrixMultiply(A [][]float64, B [][]float64) [][]float64 {
	n := len(A)

	// check if its N by N
	if n != len(B) || n != len(B[0]) {
		return nil
	}

	c := makeMatrix(n)

	// populate the matrix product
	for i := range n {
		for k := range n {
			for j := range n {
				c[i][j] += A[i][k] * B[k][j]
			}
		}
	}

	return c
}

func ParalleMatrixMultiply(A [][]float64, B [][]float64) [][]float64 {
	n := len(A)

	// check if it is n by n
	if n != len(B) || n != len(B[0]) {
		return nil
	}

	c := makeMatrix(n)

	var wg sync.WaitGroup

	for i := range n {
		x := i
		wg.Add(1)
		go func() {
			defer wg.Done()
			for k := range n {
				for j := range n {
					c[x][j] += A[x][k] * B[k][j]
				}
			}
		}()
	}

	return c
}

func generateMatrix(n int) [][]float64 {
	seed := rand.NewSource(time.Now().UnixNano())
	random := rand.New(seed)

	c := make([][]float64, n)
	for i := range c {
		c[i] = make([]float64, n)
		for j := range c {
			c[i][j] = random.Float64() * float64(random.Intn(1000))
		}
	}

	return c
}

func makeMatrix(n int) [][]float64 {
	c := make([][]float64, n)
	for i := range c {
		c[i] = make([]float64, n)
	}

	return c
}

func main() {
	n := 4096
	A := generateMatrix(n)
	B := generateMatrix(n)

	start := time.Now()
	MatrixMultiply(A, B)
	duration := time.Since(start)
	fmt.Println(duration)

	start = time.Now()
	ParalleMatrixMultiply(A, B)
	duration = time.Since(start)
	fmt.Println(duration)
}
