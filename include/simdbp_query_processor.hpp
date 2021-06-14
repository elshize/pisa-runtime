#pragma once

#include <vector>

#include <index_types.hpp>
#include <wand_data.hpp>
#include <wand_data_raw.hpp>

#include "query_processor.hpp"

class SimdBpQueryProcessor: public QueryProcessor {
  private:
    pisa::block_simdbp_index m_index;
    pisa::wand_data<pisa::wand_data_raw> m_wdata;

  public:
    SimdBpQueryProcessor(std::string const& path, std::string const& wand_data_filename);
    auto process_query(pisa::Query) -> std::vector<std::pair<float, uint64_t>> override;
    auto processor(std::string_view algorithm, ScorerParams scorer_params, std::size_t k)
        -> ProcFunc override;
    ~SimdBpQueryProcessor();
};
