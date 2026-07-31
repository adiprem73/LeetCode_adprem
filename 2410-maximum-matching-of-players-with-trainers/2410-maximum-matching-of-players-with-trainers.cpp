class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int player = 0;
    int trainer = 0;
    int matched = 0;

    while (player < players.size() && trainer < trainers.size()) {
        if (players[player] <= trainers[trainer]) {
            // This trainer can train this player
            matched++;
            player++;
            trainer++;
        } else {
            // Trainer too weak, try a stronger trainer
            trainer++;
        }
    }

    return matched;
}
};