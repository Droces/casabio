<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Qualcomm;

use PHPExiftool\Driver\AbstractTag;

class R2TL84RedCtbl13 extends AbstractTag
{

    protected $Id = 'r2_tl84_red_ctbl[13]';

    protected $Name = 'R2TL84RedCtbl13';

    protected $FullName = 'Qualcomm::Main';

    protected $GroupName = 'Qualcomm';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Qualcomm';

    protected $g2 = 'Camera';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'R2 TL84 Red Ctbl 13';

    protected $flag_Permanent = true;

}
