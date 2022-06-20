// A JavaScript program to find maximal
// Bipartite matching.

// M is number of applicants
// and N is number of jobs
let M = 4;
let N = 4;

// A DFS based recursive function that
// returns true if a matching for
// vertex u is possible
function bpm(bpGraph, u, seen, matchR) {
    // Try every job one by one
    for (let v = 0; v < N; v++) {
        // If applicant u is interested
        // in job v and v is not visited
        if (bpGraph[u][v] && !seen[v]) {
            // Mark v as visited
            seen[v] = true;

            // If job 'v' is not assigned to
            // an applicant OR previously
            // assigned applicant for job v (which
            // is matchR[v]) has an alternate job available.
            // Since v is marked as visited in the
            // above line, matchR[v] in the following
            // recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number
// of matching from M to N
function maxBPM(a) {
    // An array to keep track of the
    // applicants assigned to jobs.
    // The value of matchR[i] is the
    // applicant number assigned to job i,
    // the value -1 indicates nobody is assigned.
    let matchR = new Array(N);

    // Initially all jobs are available
    for (let i = 0; i < N; ++i) matchR[i] = -1;

    // Count of jobs assigned to applicants
    let result = 0;
    for (let u = 0; u < M; u++) {
        // Mark all jobs as not seen
        // for next applicant.
        let seen = new Array(N);
        for (let i = 0; i < N; ++i) seen[i] = false;

        // Find if the applicant 'u' can get a job
        if (bpm(a, u, seen, matchR)) result++;
    }
    return result;
}

// Let us create a bpGraph shown
// in the above example
let bpGraph = [
    [0, 1, 1, 0, 0, 0],
    [1, 0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0, 0],
    [0, 0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1],
];

let bpGraph2 = [
    [0, 0, 1, 1],
    [0, 0, 1, 1],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
];

console.log(
    "Maximum number of applicants that can" + " get job is " + maxBPM(bpGraph)
);
