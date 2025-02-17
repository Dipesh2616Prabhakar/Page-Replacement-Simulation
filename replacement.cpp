// Code to implement LRU Page Replacement
void LRU(vector<int> pages, int frames)
{
    unordered_map<int, int> pageMap;
    int pageFaults = 0;

    cout << "\nLRU Page Replacement Algorithm:\n";
    for (int i = 0; i < pages.size(); i++)
    {
        if (pageMap.find(pages[i]) == pageMap.end())
        { // Page fault
            if (pageMap.size() >= frames)
            {
                int lru = INT_MAX, pageToRemove;
                for (auto p : pageMap)
                {
                    if (p.second < lru)
                    {
                        lru = p.second;
                        pageToRemove = p.first;
                    }
                }
                pageMap.erase(pageToRemove);
            }
            pageFaults++;
        }
        pageMap[pages[i]] = i; // Update last used index
    }
    cout << "Total Page Faults: " << pageFaults << endl;
    saveResults("LRU", pageFaults);
}
